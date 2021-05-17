
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class FieldDoctor: public Player{

    public:

        FieldDoctor(Board &board, enum City);
        Player& treat(enum City);
        string role();

};