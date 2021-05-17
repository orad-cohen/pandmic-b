#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
namespace pandemic{
class Player {
   
    protected:
    static const int MAX_CARDS =48;
    static const int Default = 5;
    void CheckHand(enum City);
    bool isConnected(enum City, enum City);
    void treatHelper(enum City,bool);
    void discover_helper(Color, bool,bool, int);
    Board *_Board;
    enum City thisCity;
    unordered_map<enum City, bool> _Hand;
    std::unordered_map<enum City ,Board::CityDetails>& WorldMap(){
        return _Board->WorldMap;
    }
    std::unordered_map<enum Color, bool>& Cure(){
        return _Board->Cure;
    }

    public:
    Player(){}
    Player(Board  &b, enum City c):_Board(&b),thisCity(c){}
    virtual Player& drive (enum City);
    virtual Player& fly_direct(enum City);
    virtual Player& fly_shuttle(enum City);
    virtual Player& fly_charter(enum City);
    virtual Player& build();
    virtual Player& discover_cure(enum Color);
    virtual Player& treat(enum City);
    virtual string role() =0;
    Player& take_card(enum City);
};
}
