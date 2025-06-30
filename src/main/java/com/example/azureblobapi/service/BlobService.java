
package com.example.azureblobapi.service;

import com.azure.storage.blob.*;
import com.azure.storage.common.StorageSharedKeyCredential;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.nio.charset.StandardCharsets;

@Service
public class BlobService {

    @Value("${azure.storage.account-name}")
    private String accountName;

    @Value("${azure.storage.account-key}")
    private String accountKey;

    @Value("${azure.storage.blob-url}")
    private String blobUrl;

    public String getJsonFromBlob() {
        try {
            BlobClient blobClient = new BlobClientBuilder()
                    .endpoint(blobUrl)
                    .credential(new StorageSharedKeyCredential(accountName, accountKey))
                    .buildClient();

            byte[] content = blobClient.downloadContent().toBytes();
            return new String(content, StandardCharsets.UTF_8);
        } catch (Exception e) {
            return "Erro ao acessar blob: " + e.getMessage();
        }
    }
    public String getJsonFromSpecificBlob(String customBlobUrl) {
    try {
        BlobClient blobClient = new BlobClientBuilder()
                .endpoint(customBlobUrl)
                .credential(new StorageSharedKeyCredential(accountName, accountKey))
                .buildClient();

        byte[] content = blobClient.downloadContent().toBytes();
        return new String(content, StandardCharsets.UTF_8);
    } catch (Exception e) {
        return "Erro ao acessar blob customizado: " + e.getMessage();
    }
}
}
