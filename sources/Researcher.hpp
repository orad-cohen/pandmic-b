
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Researcher: public Player{

    public:

        Researcher(Board &board, enum City);
        Player& discover_cure(enum Color);
        string role();

};