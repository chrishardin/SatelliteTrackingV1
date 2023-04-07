#include <string>

class TLE 
{
    public:
        // TLE();
        // ~TLE();
    
    protected:
        std::string _name;
        int _satelliteNumber;
        int _classification;
        int _launchYear;
        int _launchNumber;
        int _launchPiece;
        double _inclination;
        double _raan;
        double _eccentricity;
        double _perigee;
        double _meanAnomaly;
        double _meanMotion;
        int _revolutionNumber;
};