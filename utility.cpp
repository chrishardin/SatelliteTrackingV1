#include "utility.h"
// #include "TLE.h"
#include "sgp4sdp4-master/sgp4sdp4.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <math.h>
#include <chrono>

std::vector<tle_t*> Utility::parseTLE(std::string& filename)
{
    std::vector<tle_t*> dataset;
    std::ifstream file(filename);

    // Check if file can be opened
    if(!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return dataset;
    }

    std::string satName, line1, line2;

/*

SAMPLE DATA FROM TXT

CALSPHERE 1             
1 00900U 64063C   23035.57455493  .00000681  00000+0  71256-3 0  9991
2 00900  90.1800  45.2591 0028280  46.8069  74.7802 13.74078781902531
CALSPHERE 2             
1 00902U 64063E   23035.58063194  .00000052  00000+0  64970-4 0  9995
2 00902  90.1930  48.5048 0018019 188.0468 293.5406 13.52735413690152
LCS 1                   
1 01361U 65034C   23035.57030188  .00000004  00000+0 -55886-3 0  9993
2 01361  32.1356 214.1749 0010422 340.8339  19.1765  9.89302893 88219

*/

    while (std::getline(file, satName) && std::getline(file, line1) && std::getline(file, line2))
    {
        //std::cout << "satName: " << satName << std::endl;
        //std::cout << "Line1: " << line1<< std::endl;
        //std::cout << "Line2: " << line2<< std::endl;

        // Verify line1 and line2
        if (line1.substr(0, 1) != "1")
        {
            std::cerr << "[" << satName << "] First column in line1 should be 1. Found  " << line1.substr(0, 1) << '\n';
        }
        if (line2.substr(0, 1) != "2")
        {
            std::cerr << "[" << satName << "] First column in line2 should be 2. Found " << line2.substr(0, 1) << '\n';
        }


        char* x = (char*) line1.c_str();
        char* y = (char*) line2.c_str();
        char z;
        double d = 0.0;
        tle_t* tle;

        // Store information into object
        // try_parse(satName.substr(0, 23), tle.name);
        // try_parse(line1.substr(2, 6), tle.satelliteNumber);
        // try_parse(line1.substr(7, 1), tle.classification);
        // try_parse(line1.substr(9, 2), tle.launchYear);
        // try_parse(line1.substr(11, 3), tle.launchNumber);
        // try_parse(line1.substr(14, 3), tle.launchPiece);
        // try_parse(line1.substr(18, 2), tle.epochYear);
        // try_parse(line1.substr(20, 13), tle.epochDay);
        // try_parse(line1.substr(33, 11), tle.firstDervMeanMotion);
        // try_parse(line1.substr(44, 8), tle.secondDervMeanMotion);
        // double bstar;
        // try_parse(line1.substr(53,6), bstar);
        // if (line1.substr(52,1) == "-")
        // {
        //     bstar *= -1.0;
        // }
        // double new_bstar;
        // try_parse(line1.substr(59,61), new_bstar);
        // bstar *= pow(10.0, new_bstar);
        // tle.bStar = bstar;
        // try_parse(line1.substr(62, 1), tle.ephemerisType);
        // try_parse(line1.substr(64, 4), tle.elementSetNumber);
        // try_parse(line1.substr(68, 1), tle.checksumLine1);

        // try_parse(line2.substr(8, 8), tle.inclination);
        // try_parse(line2.substr(17, 8), tle.raan);
        // try_parse("0." + line2.substr(26, 7), tle.eccentricity);
        // try_parse(line2.substr(34, 8), tle.perigee);
        // try_parse(line2.substr(43, 8), tle.meanAnomaly);
        // try_parse(line2.substr(52, 11), tle.meanMotion);
        // try_parse(line2.substr(63, 5), tle.revolutionNumber);
        // try_parse(line2.substr(68, 1), tle.checksumLine2);
        // Store object in vector
        //dataset.push_back(satrec);
    }

    return dataset;    
}


void Utility::printTLE(const TLE& tle)
{
    std::cout << "Name: " << tle.name << std::endl;
    std::cout << "SatelliteNum: " << tle.satelliteNumber << std::endl;
    std::cout << "Classification: " << tle.classification << std::endl;
    std::cout << "LaunchYear: " << tle.launchYear << std::endl;
    std::cout << "LaunchNum: " << tle.launchNumber << std::endl;
    std::cout << "launchPiece: " << tle.launchPiece << std::endl;
    std::cout << "epochYear: " << tle.epochYear << std::endl;
    std::cout << "epochDay: " << tle.epochDay << std::endl;
    std::cout << "firstDervMeanMotion: " << tle.firstDervMeanMotion << std::endl;
    std::cout << "secondDervMeanMotion: " << tle.secondDervMeanMotion << std::endl;
    std::cout << "bStar: " << tle.bStar << std::endl;
    std::cout << "ephemerisType: " << tle.ephemerisType << std::endl;
    std::cout << "elementSetNumber: " << tle.elementSetNumber << std::endl;
    std::cout << "checksumLine1: " << tle.checksumLine1 << std::endl;
    std::cout << "inclination: " << tle.inclination << std::endl;
    std::cout << "raan: " << tle.raan << std::endl;
    std::cout << "eccentricity: " << tle.eccentricity << std::endl;
    std::cout << "perigee: " << tle.perigee << std::endl;
    std::cout << "meanAnomaly: " << tle.meanAnomaly << std::endl;
    std::cout << "meanMotion: " << tle.meanMotion << std::endl;
    std::cout << "revolutionNumber: " << tle.revolutionNumber << std::endl;
    std::cout << "checksumLine2: " << tle.checksumLine2 << std::endl;
}

int Utility::getJulianTime()
{
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::gmtime(&now_c);

    // Convert the time to Julian time
    int y = now_tm.tm_year + 1900;
    int m = now_tm.tm_mon + 1;
    int d = now_tm.tm_mday;

    int a = (14 - m) / 12;
    int yy = y + 4800 - a;
    int mm = m + 12 * a - 3;
    int julian = d + (153 * mm + 2) / 5 + 365 * yy + yy / 4 - yy / 100 + yy / 400 - 32045;

    std::cout << "The current Julian time is: " << julian << std::endl;

    return julian;
}

template <typename T>
bool Utility::try_parse(const std::string& str, T& val)
{
    try
    {
        // Check if val is of type int
        if constexpr (std::is_same<T, int>::value)
        {
            val = std::stoi(str);
        }
        // Check if val is of type double
        else if constexpr (std::is_same<T, double>::value)
        {
            val = std::stod(str);
        }
        // Check if val is of type char
        else if constexpr (std::is_same<T, char>::value)
        {
            val = str;
        }
        // Check if val is of type string
        else if constexpr (std::is_same<T, std::string>::value)
        {
            val = str;
        }
        return true;
    }
    catch(const std::invalid_argument& err)
    {
        std::cerr << err.what() << '\n';
        return false;
    }
}
