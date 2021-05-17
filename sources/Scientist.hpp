
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Scientist: public Player{
        int toDiscover=5;
    public:

        Scientist(Board &board, enum City, int);
        Player& discover_cure(enum Color);
        string role();

};