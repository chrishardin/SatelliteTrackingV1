#include "sgp4sdp4-master/sgp4sdp4.h"

#include <string>
#include <vector>

// class TLE;

struct TLE {
    // sat title
    std::string name;
    // Line 1
    int satelliteNumber;
    std::string classification;
    int launchYear;
    int launchNumber;
    std::string launchPiece;
    int epochYear;
    double epochDay;
    double firstDervMeanMotion;
    double secondDervMeanMotion;
    double bStar;
    int ephemerisType;
    int elementSetNumber;
    int checksumLine1;
    // Line 2
    double inclination;
    double raan;
    double eccentricity;
    double perigee;
    double meanAnomaly;
    double meanMotion;
    int revolutionNumber;
    int checksumLine2;
};

class Utility
{
    public:
        static std::vector<tle_t*> parseTLE(std::string& filename);
        static void printTLE(const TLE& tle);
        static int getJulianTime();

    protected:
        template <typename T>
        static bool try_parse(const std::string& str, T& val);

};