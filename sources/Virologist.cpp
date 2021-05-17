#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Virologist.hpp"
using namespace pandemic;

Virologist::Virologist(Board &board, enum City city){
    _Board = &board;
    thisCity = city;
}
Player& Virologist::treat(enum City a){
    if(thisCity!=a){
        CheckHand(a);
        _Hand[a]=false;
    }    
    treatHelper(a,false);
    
    return *this;
}
string Virologist::role(){
    return "Virologist";
}