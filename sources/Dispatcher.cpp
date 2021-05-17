#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"
using namespace pandemic;


Dispatcher::Dispatcher(Board &board, enum City city){
    thisCity = city;
    _Board = &board;
    
}
Player& Dispatcher::fly_direct(enum City city){
    if(city==thisCity){
        throw invalid_argument("Already in this city");
    }
    if(!WorldMap()[thisCity].ResearchFacility){
        Player::fly_direct(city);
    }
    else{
        thisCity = city;
    }
    
    return *this;
}
string Dispatcher::role(){
    return "Dispatcher";
}