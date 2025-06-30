package com.example.azureblobapi.model;

import com.fasterxml.jackson.annotation.JsonProperty;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;

@Entity
public class FlightInstrumentation {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @JsonProperty("Airspeed")
    private double airspeed;

    @JsonProperty("Altitude")
    private double altitude;

    @JsonProperty("Airspeed True")
    private double airspeedTrue;

    @JsonProperty("Airspeed Barber Pole")
    private double airspeedBarberPole;

    @JsonProperty("Vertical Speed")
    private double verticalSpeed;

    @JsonProperty("Mach")
    private double mach;

    @JsonProperty("Stall Warning")
    private boolean stallWarning;

    @JsonProperty("Overspeed Warning")
    private boolean overspeedWarning;

    @JsonProperty("Barber Pole Mach")
    private double barberPoleMach;

    @JsonProperty("Kohlsman Setting MB")
    private double kohlsmanSettingMb;

    @JsonProperty("Kohlsman Setting HG")
    private double kohlsmanSettingHg;

    @JsonProperty("Attitude Pitch")
    private double attitudePitch;

    @JsonProperty("Attitude Bank")
    private double attitudeBank;

    @JsonProperty("Attitude Bars")
    private double attitudeBars;

    @JsonProperty("Attitude Cage")
    private boolean attitudeCage;

    @JsonProperty("Whiskey Compass")
    private double whiskeyCompass;

    @JsonProperty("Plane Heading")
    private double planeHeading;

    @JsonProperty("Heading Indicator")
    private double headingIndicator;

    @JsonProperty("Gyro Drift Error")
    private double gyroDriftError;

    @JsonProperty("Delta Heading Rate")
    private double deltaHeadingRate;

    @JsonProperty("Turn Coordinator Ball")
    private double turnCoordinatorBall;

    @JsonProperty("Angle of Attack")
    private double angleOfAttack;

    @JsonProperty("Radio Height")
    private double radioHeight;

    @JsonProperty("Max G Force")
    private double maxGForce;

    @JsonProperty("Min G Force")
    private double minGForce;

    @JsonProperty("Suction Pressure")
    private double suctionPressure;

    // Getters e Setters

    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }

    public double getAirspeed() { return airspeed; }
    public void setAirspeed(double airspeed) { this.airspeed = airspeed; }

    public double getAltitude() { return altitude; }
    public void setAltitude(double altitude) { this.altitude = altitude; }

    public double getAirspeedTrue() { return airspeedTrue; }
    public void setAirspeedTrue(double airspeedTrue) { this.airspeedTrue = airspeedTrue; }

    public double getAirspeedBarberPole() { return airspeedBarberPole; }
    public void setAirspeedBarberPole(double airspeedBarberPole) { this.airspeedBarberPole = airspeedBarberPole; }

    public double getVerticalSpeed() { return verticalSpeed; }
    public void setVerticalSpeed(double verticalSpeed) { this.verticalSpeed = verticalSpeed; }

    public double getMach() { return mach; }
    public void setMach(double mach) { this.mach = mach; }

    public boolean isStallWarning() { return stallWarning; }
    public void setStallWarning(boolean stallWarning) { this.stallWarning = stallWarning; }

    public boolean isOverspeedWarning() { return overspeedWarning; }
    public void setOverspeedWarning(boolean overspeedWarning) { this.overspeedWarning = overspeedWarning; }

    public double getBarberPoleMach() { return barberPoleMach; }
    public void setBarberPoleMach(double barberPoleMach) { this.barberPoleMach = barberPoleMach; }

    public double getKohlsmanSettingMb() { return kohlsmanSettingMb; }
    public void setKohlsmanSettingMb(double kohlsmanSettingMb) { this.kohlsmanSettingMb = kohlsmanSettingMb; }

    public double getKohlsmanSettingHg() { return kohlsmanSettingHg; }
    public void setKohlsmanSettingHg(double kohlsmanSettingHg) { this.kohlsmanSettingHg = kohlsmanSettingHg; }

    public double getAttitudePitch() { return attitudePitch; }
    public void setAttitudePitch(double attitudePitch) { this.attitudePitch = attitudePitch; }

    public double getAttitudeBank() { return attitudeBank; }
    public void setAttitudeBank(double attitudeBank) { this.attitudeBank = attitudeBank; }

    public double getAttitudeBars() { return attitudeBars; }
    public void setAttitudeBars(double attitudeBars) { this.attitudeBars = attitudeBars; }

    public boolean isAttitudeCage() { return attitudeCage; }
    public void setAttitudeCage(boolean attitudeCage) { this.attitudeCage = attitudeCage; }

    public double getWhiskeyCompass() { return whiskeyCompass; }
    public void setWhiskeyCompass(double whiskeyCompass) { this.whiskeyCompass = whiskeyCompass; }

    public double getPlaneHeading() { return planeHeading; }
    public void setPlaneHeading(double planeHeading) { this.planeHeading = planeHeading; }

    public double getHeadingIndicator() { return headingIndicator; }
    public void setHeadingIndicator(double headingIndicator) { this.headingIndicator = headingIndicator; }

    public double getGyroDriftError() { return gyroDriftError; }
    public void setGyroDriftError(double gyroDriftError) { this.gyroDriftError = gyroDriftError; }

    public double getDeltaHeadingRate() { return deltaHeadingRate; }
    public void setDeltaHeadingRate(double deltaHeadingRate) { this.deltaHeadingRate = deltaHeadingRate; }

    public double getTurnCoordinatorBall() { return turnCoordinatorBall; }
    public void setTurnCoordinatorBall(double turnCoordinatorBall) { this.turnCoordinatorBall = turnCoordinatorBall; }

    public double getAngleOfAttack() { return angleOfAttack; }
    public void setAngleOfAttack(double angleOfAttack) { this.angleOfAttack = angleOfAttack; }

    public double getRadioHeight() { return radioHeight; }
    public void setRadioHeight(double radioHeight) { this.radioHeight = radioHeight; }

    public double getMaxGForce() { return maxGForce; }
    public void setMaxGForce(double maxGForce) { this.maxGForce = maxGForce; }

    public double getMinGForce() { return minGForce; }
    public void setMinGForce(double minGForce) { this.minGForce = minGForce; }

    public double getSuctionPressure() { return suctionPressure; }
    public void setSuctionPressure(double suctionPressure) { this.suctionPressure = suctionPressure; }
}
