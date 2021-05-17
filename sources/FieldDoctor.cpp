#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"
using namespace pandemic;


FieldDoctor::FieldDoctor(Board &board, enum City a){
    _Board = &board;
    thisCity = a;
}
Player& FieldDoctor::treat(enum City city){
if(!isConnected(thisCity,city)&&!(thisCity==city)){
    throw invalid_argument("Can only treat adjecent cities");
}
treatHelper(city,false);
return *this;
}
string FieldDoctor::role(){
    return "FieldDoctor";
}