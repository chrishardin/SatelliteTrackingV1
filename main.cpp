#include "utility.h"
#include "sgp4sdp4-master/sgp4sdp4.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>

#define DEBUG

#ifdef DEBUG
#define TRACE(message) std::cout << message
#define TRACEIF(condition, message) if (condition) TRACE(message)
#define TRACENL(...) \
    do { \
        tracenl_impl(__VA_ARGS__); \
    } while (0)
#else
#define TRACE(message)
#define TRACEIF(condition, message)
#define TRACENL(message)
#endif

template <typename T>
void tracenl_impl(const T& arg) {
    std::printf("%s\n", arg);
}

template <typename T, typename... Args>
void tracenl_impl(const char* format, const T& first, const Args&... args) {
    std::printf("%s(%d): ", __FUNCTION__, __LINE__);
    std::printf(format, first, args...);
    std::printf("\n");
}

/*

Research and gather information about satellite orbits and how they can be calculated. 
You can use resources such as NASA's website and satellite-tracking software that already exists as reference.

Decide on a method for obtaining the data for satellite positions in real-time. 
This can be done through APIs provided by organizations such as NASA or by accessing satellite tracking databases.

Choose a programming language and develop a basic outline of the program. 
Start by creating classes or functions to handle satellite data, orbit calculation, and display.

Implement the functionality to retrieve and update satellite data in real-time.

Develop the user interface to display the satellite orbits and information. 
You can use graphics libraries such as OpenGL or DirectX to display the data in a visually appealing manner.

Test and debug the software to ensure that it is functioning correctly.

Improve and refine the software by adding additional features and addressing any issues that arise during testing.

*/

/*
Steps: (database)
Read the TLE data file: You can use the standard C++ input/output library to read the TLE data file. 
You can loop through the file line by line and extract the relevant information for each satellite.

Parse the TLE data: You can use string parsing techniques in C++ to extract the relevant information 
from each line of TLE data, such as the satellite name, catalog number, and TLE elements.

Store the data in a database: You can use a database management system such as MySQL, SQLite, or PostgreSQL to store the parsed TLE data. 
You can create a table in the database to store the TLE data for each satellite and then use SQL statements to insert the data into the database.

Connect to the database from your C++ application: You can use a database access library such as ODBC, MySQL Connector/C++, 
or SQLite C++ to connect to the database from your C++ application. You can then use the database access library to execute SQL 
statements to retrieve the TLE data for a specific satellite as needed.
*/

/*
STEPS:
Obtain TLE data: You can obtain TLE data from various sources such as NASA's Space Track, Celestrak, and others. 
You can parse this data and store it in your C++ application.

Calculate Satellite Positions: You can use a satellite orbit prediction library such as SGP4 or 
SDP4 to calculate the position of a satellite in real-time. 
These libraries take TLE data as input and output the satellite's position.

Display Satellite Positions: You can use a graphical library such as OpenGL or 
a GUI library such as Qt to display the satellite positions on a map.

Update Satellite Positions: You can use a timer or a thread to continuously 
update the satellite positions in real-time.

User Interaction: You can add user interaction features such as zooming, 
panning, and selecting satellites.

*/

int main()
{
    const std::string& filename = "./data/celestrak_data.txt";
    TRACENL("Satellite Tracking!");
    TRACENL("Parsing data... %s", filename.c_str());

    // Load TLE data from file
    std::ifstream tleFile("tle->txt");
    tle_t* tle;

    // Read TLE data into struct
    tleFile >> tle->sat_name >> tle->idesg >> tle->catnr >> tle->epoch >> tle->xndt2o >> tle->xndd6o >> tle->bstar
            >> tle->xincl >> tle->xnodeo >> tle->eo >> tle->omegao >> tle->xmo >> tle->xno >> tle->revnum;

    // Convert TLE data to radians
    tle->xincl *= 1.74532925E-2;
    tle->xnodeo *= 1.74532925E-2;
    tle->omegao *= 1.74532925E-2;
    tle->xmo *= 1.74532925E-2;

    // Set the time in minutes since the TLE epoch
    double tsince = (60.0 * 60.0 * 24.0) / 1.44E3;

    // Initialize the satellite's position and velocity vectors
    vector_t* pos;
    vector_t* vel;
    X::SGP4(tsince, tle, pos, vel);

    // Convert position vector to geodetic coordinates
    geodetic_t* geo;
    X::Calculate_LatLonAlt(tsince, pos, geo);
    
    // Output the satellite's latitude, longitude, and altitude
    std::cout << "Latitude: " << geo->lat << " degrees" << std::endl;
    std::cout << "Longitude: " << geo->lon << " degrees" << std::endl;
    std::cout << "Altitude: " << geo->alt << " km" << std::endl;


    // Get the current time in UTC
    auto julian = Utility::getJulianTime();

    // for (auto& sat : dataset)
    // {
    //     double r[3], v[3];
    //     SGP4Funcs::sgp4(sat, julian, r, v); 
    //     SGP4Funcs::cross_SGP4()
    //     std::cout << r;
    //     std::cout << v;
    //     double d;
    //     double lat, lon, alt, axis;
    //     double earth_radius = 6371.0;
    //     SGP4Funcs::rv2coe_SGP4(r, v, 398600.4418, d,axis,d,d,d,d,d,d, lat, lon, d);
    //     alt = axis = earth_radius;

    //     // Print the satellite's position
    //     std::cout << "Latitude: " << lat << "°" << std::endl;
    //     std::cout << "Longitude: " << lon << "°" << std::endl;
    //     std::cout << "Altitude: " << alt << " km" << std::endl;
    //     break;
    // }
    
    TRACENL("Parsing data completed...");
    return 0;
}
