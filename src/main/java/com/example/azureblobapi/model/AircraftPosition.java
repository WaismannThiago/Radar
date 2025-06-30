package com.example.azureblobapi.model;
import com.fasterxml.jackson.annotation.JsonProperty;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;

@Entity
public class AircraftPosition {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @JsonProperty("Ground Velocity")
    private double groundVelocity;

    @JsonProperty("Total World Velocity")
    private double totalWorldVelocity;

    @JsonProperty("Velocity Body Z")
    private double velocityBodyZ;

    @JsonProperty("Velocity Body X")
    private double velocityBodyX;

    @JsonProperty("Velocity Body Y")
    private double velocityBodyY;

    @JsonProperty("Velocity World Z")
    private double velocityWorldZ;

    @JsonProperty("Velocity World X")
    private double velocityWorldX;

    @JsonProperty("Velocity World Y")
    private double velocityWorldY;

    @JsonProperty("Acceleration World X")
    private double accelerationWorldX;

    @JsonProperty("Acceleration World Y")
    private double accelerationWorldY;

    @JsonProperty("Acceleration World Z")
    private double accelerationWorldZ;

    @JsonProperty("Acceleration Body X")
    private double accelerationBodyX;

    @JsonProperty("Acceleration Body Y")
    private double accelerationBodyY;

    @JsonProperty("Acceleration Body Z")
    private double accelerationBodyZ;

    @JsonProperty("Rotation Velocity Body X")
    private double rotationVelocityBodyX;

    @JsonProperty("Rotation Velocity Body Y")
    private double rotationVelocityBodyY;

    @JsonProperty("Rotation Velocity Body Z")
    private double rotationVelocityBodyZ;

    @JsonProperty("Relative Wind Velocity Body X")
    private double relativeWindVelocityBodyX;

    @JsonProperty("Relative Wind Velocity Body Y")
    private double relativeWindVelocityBodyY;

    @JsonProperty("Relative Wind Velocity Body Z")
    private double relativeWindVelocityBodyZ;

    @JsonProperty("Plane Alt Above Ground")
    private double planeAltAboveGround;

    @JsonProperty("Plane Latitude")
    private double planeLatitude;

    @JsonProperty("Plane Longitude")
    private double planeLongitude;

    @JsonProperty("Plane Altitude")
    private double planeAltitude;

    @JsonProperty("Plane Pitch Degrees")
    private double planePitchDegrees;

    @JsonProperty("Plane Bank Degrees")
    private double planeBankDegrees;

    @JsonProperty("Plane Heading Degrees True")
    private double planeHeadingDegreesTrue;

    @JsonProperty("Plane Heading Degrees Magnetic")
    private double planeHeadingDegreesMagnetic;

    @JsonProperty("Magvar")
    private double magvar;

    @JsonProperty("Ground Altitude")
    private double groundAltitude;

    @JsonProperty("Surface Type")
    private double surfaceType;

    @JsonProperty("Sim On Ground")
    private boolean simOnGround;

    @JsonProperty("Incidence Alpha")
    private double incidenceAlpha;

    @JsonProperty("Incidence Beta")
    private double incidenceBeta;

    @JsonProperty("Latitude")
    private double latitude;

    @JsonProperty("Longitude")
    private double longitude;

    @JsonProperty("Altitude")
    private double altitude;

    @JsonProperty("Current GPS latitude")
    private double currentGpsLatitude;

    @JsonProperty("Current GPS longitude")
    private double currentGpsLongitude;

    @JsonProperty("Current GPS altitude")
    private double currentGpsAltitude;

    @JsonProperty("Current GPS magnetic variation")
    private double currentGpsMagneticVariation;

    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }
    
    public double getGroundVelocity() { return groundVelocity; }
    public void setGroundVelocity(double groundVelocity) { this.groundVelocity = groundVelocity; }

    public double getTotalWorldVelocity() { return totalWorldVelocity; }
    public void setTotalWorldVelocity(double totalWorldVelocity) { this.totalWorldVelocity = totalWorldVelocity; }

    public double getVelocityBodyZ() { return velocityBodyZ; }
    public void setVelocityBodyZ(double velocityBodyZ) { this.velocityBodyZ = velocityBodyZ; }

    public double getVelocityBodyX() { return velocityBodyX; }
    public void setVelocityBodyX(double velocityBodyX) { this.velocityBodyX = velocityBodyX; }

    public double getVelocityBodyY() { return velocityBodyY; }
    public void setVelocityBodyY(double velocityBodyY) { this.velocityBodyY = velocityBodyY; }

    public double getVelocityWorldZ() { return velocityWorldZ; }
    public void setVelocityWorldZ(double velocityWorldZ) { this.velocityWorldZ = velocityWorldZ; }

    public double getVelocityWorldX() { return velocityWorldX; }
    public void setVelocityWorldX(double velocityWorldX) { this.velocityWorldX = velocityWorldX; }

    public double getVelocityWorldY() { return velocityWorldY; }
    public void setVelocityWorldY(double velocityWorldY) { this.velocityWorldY = velocityWorldY; }

    public double getAccelerationWorldX() { return accelerationWorldX; }
    public void setAccelerationWorldX(double accelerationWorldX) { this.accelerationWorldX = accelerationWorldX; }

    public double getAccelerationWorldY() { return accelerationWorldY; }
    public void setAccelerationWorldY(double accelerationWorldY) { this.accelerationWorldY = accelerationWorldY; }

    public double getAccelerationWorldZ() { return accelerationWorldZ; }
    public void setAccelerationWorldZ(double accelerationWorldZ) { this.accelerationWorldZ = accelerationWorldZ; }

    public double getAccelerationBodyX() { return accelerationBodyX; }
    public void setAccelerationBodyX(double accelerationBodyX) { this.accelerationBodyX = accelerationBodyX; }

    public double getAccelerationBodyY() { return accelerationBodyY; }
    public void setAccelerationBodyY(double accelerationBodyY) { this.accelerationBodyY = accelerationBodyY; }

    public double getAccelerationBodyZ() { return accelerationBodyZ; }
    public void setAccelerationBodyZ(double accelerationBodyZ) { this.accelerationBodyZ = accelerationBodyZ; }

    public double getRotationVelocityBodyX() { return rotationVelocityBodyX; }
    public void setRotationVelocityBodyX(double rotationVelocityBodyX) { this.rotationVelocityBodyX = rotationVelocityBodyX; }

    public double getRotationVelocityBodyY() { return rotationVelocityBodyY; }
    public void setRotationVelocityBodyY(double rotationVelocityBodyY) { this.rotationVelocityBodyY = rotationVelocityBodyY; }

    public double getRotationVelocityBodyZ() { return rotationVelocityBodyZ; }
    public void setRotationVelocityBodyZ(double rotationVelocityBodyZ) { this.rotationVelocityBodyZ = rotationVelocityBodyZ; }

    public double getRelativeWindVelocityBodyX() { return relativeWindVelocityBodyX; }
    public void setRelativeWindVelocityBodyX(double relativeWindVelocityBodyX) { this.relativeWindVelocityBodyX = relativeWindVelocityBodyX; }

    public double getRelativeWindVelocityBodyY() { return relativeWindVelocityBodyY; }
    public void setRelativeWindVelocityBodyY(double relativeWindVelocityBodyY) { this.relativeWindVelocityBodyY = relativeWindVelocityBodyY; }

    public double getRelativeWindVelocityBodyZ() { return relativeWindVelocityBodyZ; }
    public void setRelativeWindVelocityBodyZ(double relativeWindVelocityBodyZ) { this.relativeWindVelocityBodyZ = relativeWindVelocityBodyZ; }

    public double getPlaneAltAboveGround() { return planeAltAboveGround; }
    public void setPlaneAltAboveGround(double planeAltAboveGround) { this.planeAltAboveGround = planeAltAboveGround; }

    public double getPlaneLatitude() { return planeLatitude; }
    public void setPlaneLatitude(double planeLatitude) { this.planeLatitude = planeLatitude; }

    public double getPlaneLongitude() { return planeLongitude; }
    public void setPlaneLongitude(double planeLongitude) { this.planeLongitude = planeLongitude; }

    public double getPlaneAltitude() { return planeAltitude; }
    public void setPlaneAltitude(double planeAltitude) { this.planeAltitude = planeAltitude; }

    public double getPlanePitchDegrees() { return planePitchDegrees; }
    public void setPlanePitchDegrees(double planePitchDegrees) { this.planePitchDegrees = planePitchDegrees; }

    public double getPlaneBankDegrees() { return planeBankDegrees; }
    public void setPlaneBankDegrees(double planeBankDegrees) { this.planeBankDegrees = planeBankDegrees; }

    public double getPlaneHeadingDegreesTrue() { return planeHeadingDegreesTrue; }
    public void setPlaneHeadingDegreesTrue(double planeHeadingDegreesTrue) { this.planeHeadingDegreesTrue = planeHeadingDegreesTrue; }

    public double getPlaneHeadingDegreesMagnetic() { return planeHeadingDegreesMagnetic; }
    public void setPlaneHeadingDegreesMagnetic(double planeHeadingDegreesMagnetic) { this.planeHeadingDegreesMagnetic = planeHeadingDegreesMagnetic; }

    public double getMagvar() { return magvar; }
    public void setMagvar(double magvar) { this.magvar = magvar; }

    public double getGroundAltitude() { return groundAltitude; }
    public void setGroundAltitude(double groundAltitude) { this.groundAltitude = groundAltitude; }

    public double getSurfaceType() { return surfaceType; }
    public void setSurfaceType(double surfaceType) { this.surfaceType = surfaceType; }

    public boolean isSimOnGround() { return simOnGround; }
    public void setSimOnGround(boolean simOnGround) { this.simOnGround = simOnGround; }

    public double getIncidenceAlpha() { return incidenceAlpha; }
    public void setIncidenceAlpha(double incidenceAlpha) { this.incidenceAlpha = incidenceAlpha; }

    public double getIncidenceBeta() { return incidenceBeta; }
    public void setIncidenceBeta(double incidenceBeta) { this.incidenceBeta = incidenceBeta; }

    public double getLatitude() { return latitude; }
    public void setLatitude(double latitude) { this.latitude = latitude; }

    public double getLongitude() { return longitude; }
    public void setLongitude(double longitude) { this.longitude = longitude; }

    public double getAltitude() { return altitude; }
    public void setAltitude(double altitude) { this.altitude = altitude; }

    public double getCurrentGpsLatitude() { return currentGpsLatitude; }
    public void setCurrentGpsLatitude(double currentGpsLatitude) { this.currentGpsLatitude = currentGpsLatitude; }

    public double getCurrentGpsLongitude() { return currentGpsLongitude; }
    public void setCurrentGpsLongitude(double currentGpsLongitude) { this.currentGpsLongitude = currentGpsLongitude; }

    public double getCurrentGpsAltitude() { return currentGpsAltitude; }
    public void setCurrentGpsAltitude(double currentGpsAltitude) { this.currentGpsAltitude = currentGpsAltitude; }

    public double getCurrentGpsMagneticVariation() { return currentGpsMagneticVariation; }
    public void setCurrentGpsMagneticVariation(double currentGpsMagneticVariation) { this.currentGpsMagneticVariation = currentGpsMagneticVariation; }
}
