package com.example.azureblobapi.controller;

import com.azure.storage.blob.BlobClient;
import com.azure.storage.blob.BlobContainerClient;
import com.azure.storage.blob.BlobServiceClient;
import com.azure.storage.blob.BlobServiceClientBuilder;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.CrossOrigin;  // <--- Import necessário
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import org.springframework.beans.factory.annotation.Autowired;
import com.example.azureblobapi.service.BlobDataIngestionService;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

@RestController
public class BlobController {

    // ========== PROPRIEDADES ==========
    @Value("${azure.storage.account-name}")
    private String accountName;

    @Value("${azure.storage.account-key}")
    private String accountKey;

    @Value("${azure.storage.container-name}")
    private String containerName;

    @Value("${azure.storage.container-name-instrumentation}")
    private String containerNameinstrumentation;

    @Value("${azure.storage.blob-name}")
    private String blobName;

    @Value("${azure.storage.blob-name-instrumentation}")
    private String blobNameinstrumentation;

    @Autowired
    private BlobDataIngestionService ingestionService;

    // ========== ENDPOINTS DE DOWNLOAD DIRETO ==========
    @CrossOrigin(origins = "*")
    @GetMapping(value = "/blob", produces = MediaType.APPLICATION_JSON_VALUE)
    public String getBlobJson() throws IOException {
        String connectionString = String.format(
            "DefaultEndpointsProtocol=https;AccountName=%s;AccountKey=%s;EndpointSuffix=core.windows.net",
            accountName, accountKey);

        BlobServiceClient serviceClient = new BlobServiceClientBuilder()
                .connectionString(connectionString)
                .buildClient();

        BlobContainerClient containerClient = serviceClient.getBlobContainerClient(containerName);
        BlobClient blobClient = containerClient.getBlobClient(blobName);

        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        blobClient.download(outputStream);

        return outputStream.toString("UTF-8");
    }

    @GetMapping(value = "/instrumentation", produces = MediaType.APPLICATION_JSON_VALUE)
    public String getBlobJsonInstrumentation() throws IOException {
        String connectionString = String.format(
            "DefaultEndpointsProtocol=https;AccountName=%s;AccountKey=%s;EndpointSuffix=core.windows.net",
            accountName, accountKey);

        BlobServiceClient serviceClient = new BlobServiceClientBuilder()
                .connectionString(connectionString)
                .buildClient();

        BlobContainerClient containerClient = serviceClient.getBlobContainerClient(containerNameinstrumentation);
        BlobClient blobClient = containerClient.getBlobClient(blobNameinstrumentation);

        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        blobClient.download(outputStream);

        return outputStream.toString("UTF-8");
    }

    // ========== ENDPOINTS DE IMPORTAÇÃO (via serviço) ==========
    @GetMapping("/import/position")
    public String importPositionData() {
        return ingestionService.importAircraftPositionData(
            "https://datacenterproducao005.blob.core.windows.net/aircraft-position-and-speed-data/AircraftPositionandSpeedData.json"
        );
    }

    @GetMapping("/import/instrumentation")
    public String importInstrumentationData() {
        return ingestionService.importFlightInstrumentationData(
            "https://datacenterproducao005.blob.core.windows.net/aircraft-flight-instrumentation-data/AircraftFlightInstrumentationData.json"
        );
    }
}

