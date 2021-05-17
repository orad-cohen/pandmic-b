#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"

using namespace pandemic;


OperationsExpert::OperationsExpert(Board &board, enum City city){
   thisCity = city;
   _Board = &board;
}
Player& OperationsExpert::build(){    

WorldMap().at(thisCity).ResearchFacility=true;
return *this;
}
string OperationsExpert::role(){
    return "OperationsExpert";
}
