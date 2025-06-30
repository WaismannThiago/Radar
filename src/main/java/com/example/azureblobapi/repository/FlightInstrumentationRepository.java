package com.example.azureblobapi.repository;

import com.example.azureblobapi.model.FlightInstrumentation;
import org.springframework.data.jpa.repository.JpaRepository;

public interface FlightInstrumentationRepository extends JpaRepository<FlightInstrumentation, Long> {
}
