#include <windows.h>
#include <iostream>
#include <SimConnect.h>
#include <fstream>
#include <thread>

#define DEFINITION_1 1
#define REQUEST_1 1

struct LatLonAlt {
    double latitude;
    double longitude;
    double altitude;
};

struct FlightData
{
    double groundvelocity;
    double totalworldvelocity;
    double velocitybodyz;
    double velocitybodyx;
    double velocitybodyy;
    double velocityworldz;
    double velocityworldx;
    double velocityworldy;
    double accelerationworldx;
    double accelerationworldy;
    double accelerationworldz;
    double accelerationbodyx;
    double accelerationbodyy;
    double accelerationbodyz;
    double rotationvelocitybodyx;
    double rotationvelocitybodyy;
    double rotationvelocitybodyz;
    double relativewindvelocitybodyx;
    double relativewindvelocitybodyy;
    double relativewindvelocitybodyz;
    double planealtaboveground;
    double planelatitude;
    double planelongitude;
    double planealtitude;
    double planepitchdegrees;
    double planebankdegrees;
    double planeheadingdegreestrue;
    double planeheadingdegreesmagnetic;
    double magvar;
    double groundaltitude;
    double surfacetype;
    double simonground;
    double incidencealpha;
    double incidencebeta;
    double gpslatitudedegrees;
    double gpslongitudedegrees;
    double gpsaltitudegrees;
    double gpsmagneticvariation;
    LatLonAlt structlatlonalt;

};

void SaveFlightDataToTXT(const FlightData* pFlightData)
{
    std::ofstream outFile("AircraftPositionandSpeedData.txt", std::ios::trunc);
    if (!outFile.is_open())
    {
        std::cerr << "Falha ao abrir o arquivo de saída." << std::endl;
        return;
    }

    outFile << "Ground Velocity: " << pFlightData->groundvelocity << " knots\n";
    outFile << "Total World Velocity: " << pFlightData->totalworldvelocity << " feet per second\n";
    outFile << "Velocity Body Z: " << pFlightData->velocitybodyz << " feet per second\n";
    outFile << "Velocity Body X: " << pFlightData->velocitybodyx << " feet per second\n";
    outFile << "Velocity Body Y: " << pFlightData->velocitybodyy << " feet per second\n";
    outFile << "Velocity World Z: " << pFlightData->velocityworldz << " feet per second\n";
    outFile << "Velocity World X: " << pFlightData->velocityworldx << " feet per second\n";
    outFile << "Velocity World Y: " << pFlightData->velocityworldy << " feet per second\n";
    outFile << "Acceleration World X: " << pFlightData->accelerationworldx << " feet per second squared\n";
    outFile << "Acceleration World Y: " << pFlightData->accelerationworldy << " feet per second squared\n";
    outFile << "Acceleration World Z: " << pFlightData->accelerationworldz << " feet per second squared\n";
    outFile << "Acceleration Body X: " << pFlightData->accelerationbodyx << " feet per second squared\n";
    outFile << "Acceleration Body Y: " << pFlightData->accelerationbodyy << " feet per second squared\n";
    outFile << "Acceleration Body Z: " << pFlightData->accelerationbodyz << " feet per second squared\n";
    outFile << "Rotation Velocity Body X: " << pFlightData->rotationvelocitybodyx << " feet per second\n";
    outFile << "Rotation Velocity Body Y: " << pFlightData->rotationvelocitybodyy << " feet per second\n";
    outFile << "Rotation Velocity Body Z: " << pFlightData->rotationvelocitybodyz << " feet per second\n";
    outFile << "Relative Wind Velocity Body X: " << pFlightData->relativewindvelocitybodyx << " feet per second\n";
    outFile << "Relative Wind Velocity Body Y: " << pFlightData->relativewindvelocitybodyy << " feet per second\n";
    outFile << "Relative Wind Velocity Body Z: " << pFlightData->relativewindvelocitybodyz << " feet per second\n";
    outFile << "Plane Alt Above Ground: " << pFlightData->planealtaboveground << " feet\n";
    outFile << "Plane Latitude: " << pFlightData->planelatitude << " radians\n";
    outFile << "Plane Longitude: " << pFlightData->planelongitude << " radians\n";
    outFile << "Plane Altitude: " << pFlightData->planealtitude << " feet\n";
    outFile << "Plane Pitch Degrees: " << pFlightData->planepitchdegrees << " radians\n";
    outFile << "Plane Bank Degrees: " << pFlightData->planebankdegrees << " radians\n";
    outFile << "Plane Heading Degrees True: " << pFlightData->planeheadingdegreestrue << " radians\n";
    outFile << "Plane Heading Degrees Magnetic: " << pFlightData->planeheadingdegreesmagnetic << " radians\n";
    outFile << "Magvar: " << pFlightData->magvar << " degrees\n";
    outFile << "Ground Altitude: " << pFlightData->groundaltitude << " meters\n";
    outFile << "Surface Type: " << pFlightData->surfacetype << " (surface ID)\n";
    outFile << "Sim On Ground: " << (pFlightData->simonground ? "Yes" : "No") << "\n";
    outFile << "Incidence Alpha: " << pFlightData->incidencealpha << " radians\n";
    outFile << "Incidence Beta: " << pFlightData->incidencebeta << " radians\n";
    outFile << "Latitude: " << pFlightData->structlatlonalt.latitude << " radians\n";
    outFile << "Longitude: " << pFlightData->structlatlonalt.longitude << " radians\n";
    outFile << "Altitude: " << pFlightData->structlatlonalt.altitude << " meters\n";
    outFile << "Current GPS latitude: " << pFlightData->gpslatitudedegrees << " degrees\n";
    outFile << "Current GPS longitude: " << pFlightData->gpslongitudedegrees << " degrees\n";
    outFile << "Current GPS altitude: " << pFlightData->gpsaltitudegrees << " meters\n";
    outFile << "Current GPS magnetic variation: " << pFlightData->gpsmagneticvariation << " radians\n";

    outFile << "-----------------------------\n";

    outFile.close();
    std::cout << "Dados salvos no arquivo 'AircraftPositionandSpeedData.txt'." << std::endl;
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

    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GROUND VELOCITY", "knots"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "TOTAL WORLD VELOCITY", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "VELOCITY BODY Z", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "VELOCITY BODY X", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "VELOCITY BODY Y", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "VELOCITY WORLD Z", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "VELOCITY WORLD X", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "VELOCITY WORLD Y", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ACCELERATION WORLD X", "feet per second squared"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ACCELERATION WORLD Y", "feet per second squared"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ACCELERATION WORLD Z", "feet per second squared"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ACCELERATION BODY X", "feet per second squared"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ACCELERATION BODY Y", "feet per second squared"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ACCELERATION BODY Z", "feet per second squared"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ROTATION VELOCITY BODY X", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ROTATION VELOCITY BODY Y", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ROTATION VELOCITY BODY Z", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "RELATIVE WIND VELOCITY BODY X", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "RELATIVE WIND VELOCITY BODY Y", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "RELATIVE WIND VELOCITY BODY Z", "feet per second"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE ALT ABOVE GROUND", "feet"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE LATITUDE", "radians"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE LONGITUDE", "radians"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE PITCH DEGREES", "radians"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE BANK DEGREES", "radians"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE HEADING DEGREES TRUE", "radians"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE HEADING DEGREES MAGNETIC", "radians"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "MAGVAR", "degrees"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GROUND ALTITUDE", "meters"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "SURFACE TYPE", "enum"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "SIM ON GROUND", "bool"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "INCIDENCE ALPHA", "radians"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "INCIDENCE BETA", "radians");
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "STRUCT LATLONALT", "radians"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS POSITION LAT", "degrees"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS POSITION LON", "degrees"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS POSITION ALT", "meters"); 
    hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS MAGVAR", "radians"); 

    hr = SimConnect_RequestDataOnSimObject(
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
