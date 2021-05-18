#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

namespace pandemic{
    

class Board  {
    const static size_t _MaxConnections = 6;
    class CityDetails{
        public:
        enum City thisCity;
        std::unordered_map<enum City, bool> Adjecent;
        enum Color Disease;        
        int InfectionRate;
        bool ResearchFacility;    
        CityDetails(std::string , std::string , std::array<enum City,6>);
        CityDetails(){}

    };
    protected:    
    
    std::unordered_map<enum Color, bool> Cure;    

    public: 
    std::unordered_map<enum City ,CityDetails> WorldMap;   
    Board();
    int& operator[](enum City);

    friend ostream& operator<<(ostream& os , Board& board);

    bool is_clean();

    void remove_cures();

    void remove_stations();

    void Pr();
    static enum Color enumToColor(std::string &);
    static enum City enumToCity(string & );
    static string colorEnumToString(enum Color);
    static string cityEnumToString(enum City );

    friend class Player;

    
    
    


    
};
}
    



