#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Scientist.hpp"
using namespace pandemic;


Scientist::Scientist(Board &board, enum City city, int a){
    toDiscover= a;
    _Board = &board;
    thisCity = city;
}
Player& Scientist::discover_cure(enum Color color){
    Player::discover_helper(color , false,false,toDiscover);
    return *this;
}
string Scientist::role(){
    return "Scientist";
}