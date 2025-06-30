import requests
import time

file_path = r"C:\Projetos\FSXLogger\AircraftFlightInstrumentationData.txt"
url = "http://191.232.166.162/api.php"

def enviar_arquivo_para_api():
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            conteudo = f.read()

        headers = {
            'Content-Type': 'text/plain'
        }

        response = requests.post(url, data=conteudo, headers=headers)

        if response.status_code == 200:
            print("Dados enviados com sucesso!")
            print("Resposta da API:", response.text)
        else:
            print(f"Erro ao enviar dados. Código HTTP: {response.status_code}")
            print("Resposta:", response.text)

    except Exception as e:
        print("Erro:", e)

if __name__ == "__main__":
    while True:
        enviar_arquivo_para_api()
        print("Aguardando 1 minuto para o próximo envio...\n")
        time.sleep(60)  # Espera 60 segundos antes do próximo envio
