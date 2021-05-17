#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

TEST_CASE("GOOD TRAVEL"){
    CHECK_NOTHROW(Board board);
    Board board;
    board[City::Istanbul] = 3;
    board[City::Algiers] = 2;
    board[City::Milan] = 1;
    board[City::Baghdad] =1;
    board[City::Tehran] =2;
    board[City::Lagos] = 1;
    Virologist ViroPlayer {board,City::Miami};
    CHECK_NOTHROW(ViroPlayer.take_card(City::Paris).take_card(City::Lagos)
    .take_card(City::Karachi).take_card(City::Mumbai).take_card(City::Chennai)
    .take_card(City::Essen).take_card(City::London).take_card(City::Madrid)
    .take_card(City::Moscow).take_card(City::Baghdad).take_card(City::Miami));
    CHECK_NOTHROW(ViroPlayer.fly_direct(City::London));
    CHECK_NOTHROW(ViroPlayer.treat(City::Lagos));
    CHECK_EQ(board[City::Lagos], 0);
    CHECK_NOTHROW(ViroPlayer.drive(City::Paris));
    CHECK_NOTHROW(ViroPlayer.build());
    CHECK_NOTHROW(ViroPlayer.discover_cure(Color::Black));
    CHECK_NOTHROW(ViroPlayer.treat(City::Lagos));
    CHECK_NOTHROW(ViroPlayer.drive(City::Algiers));
    CHECK_NOTHROW(ViroPlayer.treat(City::Algiers));
    CHECK_NOTHROW(ViroPlayer.drive(City::Istanbul));
    CHECK_NOTHROW(ViroPlayer.treat(City::Istanbul));
    CHECK_EQ(board[City::Istanbul],0);
    CHECK_NOTHROW(ViroPlayer.take_card(City::Tehran));
    CHECK_NOTHROW(ViroPlayer.treat(City::Tehran));
    CHECK_EQ(board[City::Tehran],0);
    CHECK_THROWS(ViroPlayer.fly_charter(City::Johannesburg));
    CHECK_THROWS(ViroPlayer.build());
    CHECK_THROWS(ViroPlayer.drive(City::Delhi));
    CHECK_EQ(ViroPlayer.role(),"Virologist");




}

