package com.example.azureblobapi.service;

import com.example.azureblobapi.model.AircraftPosition;
import com.example.azureblobapi.model.FlightInstrumentation;
import com.example.azureblobapi.repository.AircraftPositionRepository;
import com.example.azureblobapi.repository.FlightInstrumentationRepository;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.net.URL;
import java.util.List;

@Service
public class BlobDataIngestionService {

    @Autowired
    private AircraftPositionRepository positionRepository;

    @Autowired
    private FlightInstrumentationRepository instrumentationRepository;

    private final ObjectMapper objectMapper = new ObjectMapper();

  public String importAircraftPositionData(String url) {
    try {
        AircraftPosition data = objectMapper.readValue(
            new URL(url), AircraftPosition.class
        );

        positionRepository.save(data);
        return "Importação de posições concluída. Registro salvo.";
    } catch (Exception e) {
        return "Erro ao importar posições: " + e.getMessage();
    }
}

public String importFlightInstrumentationData(String url) {
    try {
        FlightInstrumentation data = objectMapper.readValue(
            new URL(url), FlightInstrumentation.class
        );

        instrumentationRepository.save(data);
        return "Importação de instrumento concluída com sucesso.";
    } catch (Exception e) {
        return "Erro ao importar dados de instrumentação: " + e.getMessage();
    }
}


}
