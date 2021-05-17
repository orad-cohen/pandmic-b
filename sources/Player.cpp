#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include <array>
using namespace pandemic;


Player& Player::drive (enum City city){    

    if(isConnected(thisCity,city)){
        thisCity=city;
    }
    else{
        throw invalid_argument("You can't go there, City isn't connected");
    }    
    
    return *this;
}
Player& Player::fly_direct(enum City city){
    CheckHand(city);
    _Hand[city]=false;
    thisCity = city;
    return *this;
}
Player& Player::fly_shuttle(enum City city){    
    if(city==thisCity){
        throw invalid_argument("Already in the City");
    }
    if(!(WorldMap().at(city).ResearchFacility && WorldMap().at(thisCity).ResearchFacility)){
        throw invalid_argument("Can't do that, no research facility");
    }
    thisCity=city;
    return *this;
}
Player& Player::fly_charter(enum City city){
    CheckHand(thisCity);
    _Hand[thisCity]=false;
    thisCity = city;
    return *this;
}
Player& Player::build(){
    CheckHand(thisCity);
    _Board->WorldMap.at(thisCity).ResearchFacility=true;
    _Hand[thisCity]=false;
    
    return *this;
}

Player& Player::take_card(enum City city){
    _Hand[city]=true;
    return *this;
}
Player& Player::treat(enum City city){
    if(thisCity!=city){
        throw invalid_argument("You can only treat the City you are in");
    }
    treatHelper(city,false);

    return *this;
}
Player& Player::discover_cure(enum Color color){
    discover_helper(color,false,false,Default);   
    
    return *this;
}
void Player::CheckHand(enum City city){
    if(!_Hand[city]){
            throw invalid_argument("You don't have that card");
    }
}
bool Player::isConnected(enum City from, enum City to){
        return WorldMap().at(from).Adjecent.find(to)!=WorldMap().at(from).Adjecent.end();
}
void Player::treatHelper(enum City toTreat, bool isMedic){
    if(WorldMap().at(toTreat).InfectionRate==0){
        throw invalid_argument("There are no cubes in the city");
    }
    if(isMedic||Cure()[WorldMap().at(toTreat).Disease]){
        WorldMap().at(toTreat).InfectionRate=0;
    }
    else{
        WorldMap().at(toTreat).InfectionRate--;
    }
    }
void Player::discover_helper(Color color, bool isGeneSplicer,bool isResercher, int Cards){
    int CardsThrown = 0;
    array<int,Default> ErrorGuard = {-1,-1,-1,-1,-1};
    size_t GuardCount=0;
    if(!isResercher){
        if(!_Board->WorldMap.at(thisCity).ResearchFacility){
            throw invalid_argument("no research facility "+Board::CityToString(thisCity));
    }
    }
    
    if(Cure()[color]){
        return;
    }
   
    for (size_t i = 0; i < MAX_CARDS; i++)
    {   
        if(_Hand[(enum City) i]&&(isGeneSplicer||WorldMap()[(enum City)i].Disease==color)){
            CardsThrown++;
            _Hand[(enum City) i]=false;
            ErrorGuard.at(GuardCount++)=i;
        }
        if(CardsThrown==Cards){
            Cure()[color]=true;
            break;
        }
        
    }
       
    if(CardsThrown!=Cards){
        for (size_t i = 0; i <= GuardCount&&ErrorGuard.at(i)!=-1; i++)
        {   
            _Hand[(enum City)ErrorGuard.at(i)]=true;        
            
        }
        
        throw invalid_argument("not enough cards");
    }

    }

