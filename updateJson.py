import os
import json
import time
import re
from azure.storage.blob import BlobServiceClient

# === Configuração do Azure Blob ===
AZURE_CONNECTION_STRING = (
    "DefaultEndpointsProtocol=https;"
    "AccountName=datacenterproducao005;"
    "AccountKey=GuCNcBfxoe6jdfJ5ZLd1BfQOFF0RipbanvCtNcyiPvZR4WVR4lwyzQATSYabo8V9Tz3gTSgqOh73+AStyjspqA==;"
    "EndpointSuffix=core.windows.net"
)

# === Blobs e containers ===
BLOBS = [
    {
        "local_txt": r"C:\Projetos\FSXLogger\AircraftPositionandSpeedData.txt",
        "container": "aircraft-position-and-speed-data",
        "blob_name": "AircraftPositionandSpeedData.json"
    },
    {
        "local_txt": r"C:\Projetos\FSXLogger\AircraftFlightInstrumentationData.txt",
        "container": "aircraft-flight-instrumentation-data",
        "blob_name": "AircraftFlightInstrumentationData.json"
    }
]

# === Função para interpretar as linhas do TXT ===
def parse_line(line):
    if ":" not in line:
        return None, None

    key, value = line.split(":", 1)
    key = key.strip()
    value = value.strip()

    # Booleano
    if value.lower() in ["yes", "true"]:
        return key, True
    elif value.lower() in ["no", "false"]:
        return key, False

    # Tenta extrair número
    match = re.match(r"([-+eE0-9.]+)", value)
    if match:
        try:
            return key, float(match.group(1))
        except:
            return key, value

    return key, value

# === Converte TXT para JSON ===
def converter_txt_para_json(path):
    with open(path, "r", encoding="utf-8") as f:
        linhas = f.readlines()

    dados = {}
    for linha in linhas:
        if linha.strip().startswith("---"):
            continue
        chave, valor = parse_line(linha)
        if chave:
            dados[chave] = valor
    return dados

# === Envia para Azure Blob ===
def upload_para_blob(container, blob_name, dados_json):
    try:
        blob_service_client = BlobServiceClient.from_connection_string(AZURE_CONNECTION_STRING)
        blob_client = blob_service_client.get_blob_client(container=container, blob=blob_name)

        json_str = json.dumps(dados_json, indent=4)
        blob_client.upload_blob(json_str, overwrite=True)
        print(f"[✔] {time.strftime('%H:%M:%S')} - {blob_name} enviado com sucesso para '{container}'")
    except Exception as e:
        print(f"[✘] Erro ao enviar '{blob_name}': {e}")

# === Execução Principal ===
def main():
    while True:
        for blob in BLOBS:
            path = blob["local_txt"]
            if not os.path.exists(path):
                print(f"[✘] Arquivo não encontrado: {path}")
                continue

            dados = converter_txt_para_json(path)
            upload_para_blob(blob["container"], blob["blob_name"], dados)

        time.sleep(30)

if __name__ == "__main__":
    main()
