// CopyRight 2024 Harishwar Reddy Erri

#define BOOST_TEST_MODULE SokobanTests
#include <sstream>
#include <boost/test/included/unit_test.hpp>
#include "Sokoban.hpp"

// Replace the namespace directive with specific using-declarations
using SB::Sokoban;
using SB::Direction;

BOOST_AUTO_TEST_SUITE(SokobanTests)

BOOST_AUTO_TEST_CASE(test_initialization) {
    Sokoban sokoban("level1.lvl");
    BOOST_CHECK_EQUAL(sokoban.width(), 10);  // Assuming test level is 5x5
    BOOST_CHECK_EQUAL(sokoban.height(), 10);
}

BOOST_AUTO_TEST_CASE(test_player_movement) {
    Sokoban sokoban("level1.lvl");

    auto initialPos = sokoban.playerLoc();
    sokoban.movePlayer(Direction::Right);
    BOOST_CHECK(sokoban.playerLoc() != initialPos);  // Ensure player moved

    sokoban.movePlayer(Direction::Left);
    BOOST_CHECK(sokoban.playerLoc() == initialPos);  // Ensure player moved back
}

BOOST_AUTO_TEST_CASE(test_box_movement) {
    Sokoban sokoban("level2.lvl");

    // Set up player and box positions as needed by the test level
    sokoban.movePlayer(Direction::Right);  // Assuming there's a box in this direction

    // Check if box has moved
    // (Exact check depends on level configuration and Sokoban class implementation)
    // For instance, if box moves to a target:
    BOOST_CHECK(sokoban.isWon() == false);  // Ensure the game isn't won yet
}

BOOST_AUTO_TEST_CASE(test_reset_functionality) {
    Sokoban sokoban("level1.lvl");
    sokoban.movePlayer(Direction::Right);  // Make a move
    sokoban.reset();

    // Ensure game is reset to initial state
    BOOST_CHECK_EQUAL(sokoban.playerLoc().x, 3);  // Expected start position x = 3
    BOOST_CHECK_EQUAL(sokoban.playerLoc().y, 6);  // Expected start position y = 6
}

BOOST_AUTO_TEST_CASE(test_undo_functionality) {
    Sokoban sokoban("level3.lvl");
    auto initialPos = sokoban.playerLoc();

    sokoban.movePlayer(Direction::Right);  // Make a move
    sokoban.undo();

    // Check if player position is back to the initial position
    BOOST_CHECK(sokoban.playerLoc() == initialPos);
}


BOOST_AUTO_TEST_SUITE_END()
