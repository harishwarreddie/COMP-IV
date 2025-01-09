 # PS4: Sokoban

## Contact
Name: Harishwar Reddy Erri
Section: 202
Time to Complete: 6hrs


## Description

This project implements a clone of the classic game Sokoban using C++ and SFML (Simple and Fast Multimedia Library).
Sokoban is a puzzle game where a player must push boxes to specific target locations on a grid.
This project includes essential gameplay features such as movement, box interactions, level resets, an undo function, and game win detection.
The game reads levels from a file, supports simple animations, and provides sounds for movement and victory.
The graphics are handled with sprites and textures using SFML, providing a simple, visually interactive experience.
	
### Features

Game Mechanics
    Movement:
    The player can move up, down, left, and right using keyboard controls.
    
    Box Pushing:
    The player can push boxes (but not pull them), and only one box can be pushed at a time.
    
    Level Reset:
    The player can reset the level using R, restoring all boxes and the player position to their starting locations.
    
    Win Detection:
    The game detects when all boxes are correctly placed on target spots and displays a victory message.

Visuals and Audio
    Textures and Sprites:
    Each game element (e.g., player, wall, box, target) has a unique texture, making it visually distinctive on the screen.

    Sound Effects:
    Sound effects are triggered for actions such as movement and game completion, enhancing the user experience.

Timer Display
    Timer:
    A game timer is displayed, updating the player on the duration spent on the level. When the player wins, the final time is displayed.

### Memory

The game uses SFML for managing textures and sprites, storing them in arrays and vectors.
Specifically:
    Textures and Sprites:
    Textures for each element are loaded once and assigned to sprites, ensuring efficient memory use by reusing these resources.

    Grid Representation:
    The game grid is stored in a std::vector<char> m_grid, representing each cell on the grid, which is resized based on the level size.

    Undo Feature with Deque:
    The std::deque<GameState> m_undoStates stores up to two previous game states for the undo feature. 
    This limits memory usage by only retaining recent states, ensuring older ones are iscarded automatically.


### Lambdas

1.The isWon() uses a lambda expressions:
    Purpose
        This lambda function, named checkCell, is designed to examine each cell of the Sokoban grid and update various counters and flags. These updates are crucial for determining whether the puzzle has been solved.
    Functionality
        Input: The function takes a single character c as input, representing the content of a grid cell.
        Processing: It uses a switch statement to handle different cell types:
        'A': Represents a box not on a target
        'a': Represents an empty target
        '1': Represents a box on a target
        '+': Represents the player standing on a target
this lambda provide a clear, concise way to define the win condition: all boxes must be on targets, and there should be at least one box on a target.

2.The reset() uses a lambda expression within std::find_if:
    Syntax: [](char c) { return c == '@' || c == '+'; }
    Purpose: Finds the player's position in the grid.
    It checks for either '@' (player on empty space) or '+' (player on target).
This lambda allows for a concise way to locate the player's position when resetting the game state.

### Issues
None

### Extra Credit
1.Advanced Undo Feature:
    The player can undo moves back to the initial state with Z (up to two previous moves are saved).
    This version includes an undo feature with an adjustable memory capacity using a std::deque, which is efficient and gives the flexibility to add further undo steps if needed.

2.Game Timer with Win Screen:
    The game includes a fully implemented timer, displayed on-screen, and a victory message that shows the final time once the player completes the level.

3.Victory Sound:
    Plays the sound( victory.wav )automatically after the game completion.

4.Player Direction:
    player changes posture/Directions while moving.
    
5.Movement Sounds:
    Sound( move.wav) effects trigger upon actions on every movement(up, down, left, right).
   

## Acknowledgements

1.SFML Document
2.ps4a pdf from BlackBoard

Kenney Sokoban Pack (CC0): https://kenney.nl/assets/sokoban
Victory sound: https://mixkit.co/free-sound-effects/win/
Font: https://www.fontspace.com/blaze-circuit-font-f121613