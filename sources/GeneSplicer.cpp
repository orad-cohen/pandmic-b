#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"
using namespace pandemic;



GeneSplicer ::GeneSplicer(Board &board, enum City city){
    _Board = &board;
    thisCity = city;
}
Player& GeneSplicer::discover_cure(enum Color color){
        Player::discover_helper(color,true,false, Default);
    return *this;
}
string GeneSplicer::role(){
    return "GeneSplicer";
}