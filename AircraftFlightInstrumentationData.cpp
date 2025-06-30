#include <windows.h>
#include <iostream>
#include <SimConnect.h>
#include <fstream>
#include <thread>

#define DEFINITION_1 1
#define REQUEST_1 1

struct FlightData
{
    double airspeed;
    double altitude;
    double airspeedTrue;
    double airspeedBarberPole;
    double verticalSpeed;
    double mach;
    double stallWarning;
    double overspeedWarning;
    double barberPoleMach;
    double kohlsmanSettingMB;
    double kohlsmanSettingHG;
    double attitudePitch;
    double attitudeBank;
    double attitudeBars;
    double attitudeCage;
    double whiskeyCompass;
    double planeHeading;
    double headingIndicator;
    double gyroDriftError;
    double deltaHeadingRate;
    double turnCoordinatorBall;
    double angleOfAttack;
    double radioHeight;
    double partialPanelADF;
    double partialPanelAirspeed;
    double partialPanelAltimeter;
    double partialPanelAttitude;
    double partialPanelComm;
    double partialPanelCompass;
    double partialPanelElectrical;
    double partialPanelAvionics;
    double partialPanelEngine;
    double partialPanelFuelIndicator;
    double partialPanelHeading;
    double partialPanelVerticalVelocity;
    double partialPanelTransponder;
    double partialPanelNav;
    double partialPanelPitot;
    double partialPanelTurnCoordinator;
    double partialPanelVacuum;
    double maxGForce;
    double minGForce;
    double suctionPressure;
};

void SaveFlightDataToTXT(const FlightData* pFlightData)
{
    std::ofstream outFile("AircraftFlightInstrumentationData.txt", std::ios::trunc);
    if (!outFile.is_open())
    {
        std::cerr << "Falha ao abrir o arquivo de saída." << std::endl;
        return;
    }

    outFile << "Airspeed: " << pFlightData->airspeed << " knots\n";
    outFile << "Altitude: " << pFlightData->altitude << " feet\n";
    outFile << "Airspeed True: " << pFlightData->airspeedTrue << " knots\n";
    outFile << "Airspeed Barber Pole: " << pFlightData->airspeedBarberPole << " knots\n";
    outFile << "Vertical Speed: " << pFlightData->verticalSpeed << " feet per second\n";
    outFile << "Mach: " << pFlightData->mach << "\n";
    outFile << "Stall Warning: " << (pFlightData->stallWarning ? "True" : "False") << "\n";
    outFile << "Overspeed Warning: " << (pFlightData->overspeedWarning ? "True" : "False") << "\n";
    outFile << "Barber Pole Mach: " << pFlightData->barberPoleMach << "\n";
    outFile << "Kohlsman Setting MB: " << pFlightData->kohlsmanSettingMB << " mb\n";
    outFile << "Kohlsman Setting HG: " << pFlightData->kohlsmanSettingHG << " inHg\n";
    outFile << "Attitude Pitch: " << pFlightData->attitudePitch << " radians\n";
    outFile << "Attitude Bank: " << pFlightData->attitudeBank << " radians\n";
    outFile << "Attitude Bars: " << pFlightData->attitudeBars << "\n";
    outFile << "Attitude Cage: " << (pFlightData->attitudeCage ? "True" : "False") << "\n";
    outFile << "Whiskey Compass: " << pFlightData->whiskeyCompass << " degrees\n";
    outFile << "Plane Heading: " << pFlightData->planeHeading << " radians\n";
    outFile << "Heading Indicator: " << pFlightData->headingIndicator << " radians\n";
    outFile << "Gyro Drift Error: " << pFlightData->gyroDriftError << " radians\n";
    outFile << "Delta Heading Rate: " << pFlightData->deltaHeadingRate << " radians per second\n";
    outFile << "Turn Coordinator Ball: " << pFlightData->turnCoordinatorBall << "\n";
    outFile << "Angle of Attack: " << pFlightData->angleOfAttack << " radians\n";
    outFile << "Radio Height: " << pFlightData->radioHeight << " feet\n";
    outFile << "Max G Force: " << pFlightData->maxGForce << " g\n";
    outFile << "Min G Force: " << pFlightData->minGForce << " g\n";
    outFile << "Suction Pressure: " << pFlightData->suctionPressure << " inches of mercury\n";
    outFile << "-----------------------------\n";

    outFile.close();
    std::cout << "Dados salvos no arquivo 'AircraftFlightInstrumentationData.txt'." << std::endl;
}

void CALLBACK MySimConnectHandler(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext)
{
    switch (pData->dwID)
    {
        case SIMCONNECT_RECV_ID_SIMOBJECT_DATA:
        {
            SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;
            FlightData* pFlightData = (FlightData*)&pObjData->dwData;

            SaveFlightDataToTXT(pFlightData);
            break;
        }
        default:
            break;
    }
}

int main()
{
    HANDLE hSimConnect = NULL;
    HRESULT hr = SimConnect_Open(&hSimConnect, "FSXLogger", NULL, 0, 0, 0);

    if (FAILED(hr))
    {
        std::cerr << "Falha ao abrir a conexão SimConnect." << std::endl;
        return 1;
    }

    std::cout << "Conectado ao SimConnect com sucesso!" << std::endl;


    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AIRSPEED TRUE", "knots");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AIRSPEED INDICATED", "knots");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AIRSPEED TRUE CALIBRATE", "degrees");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AIRSPEED BARBER POLE", "knots");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AIRSPEED MACH", "mach");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "VERTICAL SPEED", "feet per second");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "MACH MAX OPERATE", "mach");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "STALL WARNING", "bool");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "OVERSPEED WARNING", "bool");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "BARBER POLE MACH", "mach");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "INDICATED ALTITUDE", "feet");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "KOHLSMAN SETTING MB", "millibars");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "KOHLSMAN SETTING HG", "inches of mercury");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ATTITUDE INDICATOR PITCH DEGREES", "radians");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ATTITUDE INDICATOR BANK DEGREES", "radians");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ATTITUDE BARS POSITION", "percent over 100");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ATTITUDE CAGE", "bool");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "WISKEY COMPASS INDICATION DEGREES", "degrees");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE HEADING DEGREES", "radians");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "HEADING INDICATOR", "radians");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GYRO DRIFT ERROR", "radians");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "DELTA HEADING RATE", "radians per second");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "TURN COORDINATOR BALL", "position 128 (-127 to 127)");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ANGLE OF ATTACK INDICATOR", "radians");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "RADIO HEIGHT", "feet");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL ADF", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL AIRSPEED", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL ALTIMETER", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL ATTITUDE", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL COMM", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL COMPASS", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL ELECTRICAL", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL AVIONICS", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL ENGINE", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL FUEL INDICATOR", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL HEADING", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL VERTICAL VELOCITY", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL TRANSPONDER", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL NAV", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL PITOT", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL TURN COORDINATOR", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PARTIAL PANEL VACUUM", "enum");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "MAX G FORCE", "gforce");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "MIN G FORCE", "gforce");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "SUCTION PRESSURE", "inches of mercury");


    SimConnect_RequestDataOnSimObject(
        hSimConnect,
        REQUEST_1,
        DEFINITION_1,
        SIMCONNECT_OBJECT_ID_USER,
        SIMCONNECT_PERIOD_SECOND
    );


    while (true)
    {
        SimConnect_CallDispatch(hSimConnect, MySimConnectHandler, NULL);
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }

    SimConnect_Close(hSimConnect);
    return 0;
}
