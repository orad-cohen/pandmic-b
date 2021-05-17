#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Medic.hpp"
using namespace pandemic;


Medic ::Medic(Board &board, enum City city){
    _Board = &board;
    thisCity = city;      
}
Player& Medic::treat(enum City city){
    treatHelper(city,true);
    return *this;
}
Player& Medic::drive(enum City city){
    
    if(isConnected(thisCity,city)){
        thisCity=city;
    }
    if(Cure().at(WorldMap().at(city).Disease)&&WorldMap().at(city).InfectionRate!=0){
        treatHelper(city,true);
    }
    return *this;
}

Player& Medic::fly_direct(enum City city){
    Player::fly_direct(city);    
    if(Cure()[WorldMap().at(city).Disease]&&WorldMap().at(city).InfectionRate!=0){
        treatHelper(city,true);
    }
    return *this;
}
Player& Medic::fly_shuttle(enum City city){
    Player::fly_shuttle(city);
    if(Cure()[WorldMap().at(city).Disease]&&WorldMap().at(city).InfectionRate!=0){
        treatHelper(city,true);
    }
    return *this;
}
Player& Medic::fly_charter(enum City city){
    Player::fly_charter(city);
    if(Cure()[WorldMap().at(city).Disease]&&WorldMap().at(city).InfectionRate!=0){
        treatHelper(city,true);
    }
    return *this;   
}
string Medic::role(){
    return "Medic";
}