#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
using namespace pandemic;


Researcher::Researcher(Board &board, enum City city){
    _Board = &board;
    thisCity = city;
}
Player& Researcher::discover_cure(enum Color color){
    Player::discover_helper(color,false,true,Default);
    return *this;
}
string Researcher::role(){
    return "Researcher";
}