
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class GeneSplicer: public Player{

    public:

        GeneSplicer(Board &board, enum City);
        Player& discover_cure(enum Color color);
        string role();

};