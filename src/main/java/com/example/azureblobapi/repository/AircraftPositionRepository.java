package com.example.azureblobapi.repository;

import com.example.azureblobapi.model.AircraftPosition;
import org.springframework.data.jpa.repository.JpaRepository;

public interface AircraftPositionRepository extends JpaRepository<AircraftPosition, Long> {
}
