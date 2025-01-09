 # PS4: Sokoban

## Contact
Name: Harishwar Reddy Erri
Section: 202
Time to Complete:6hrs


## Description

This project is an implementation of the classic Sokoban puzzle game using C++ and the SFML library.
Sokoban, which means "warehouse keeper" in Japanese, is a type of transport puzzle where the player pushes boxes or crates around in a warehouse, trying to get them to storage locations.
In this version, the player navigates through a grid-based level, pushing boxes onto target locations.
The game features a graphical interface, level loading from files, and a timer to track solving time.

	
### Features

1.Graphical user interface using SFML
2.Level loading from external files
3.Player movement using W, A, S, D,C keys
4.Box pushing mechanics
5.Win condition checking
6.Timer display in MM:SS format
7.Multiple levels support

### Memory

This project employs several memory management techniques and considerations:
- Use of RAII (Resource Acquisition Is Initialization) principle through C++ standard containers like `std::vector`
- Proper management of SFML resources (textures, sprites, window)
- Avoidance of raw pointers, favoring smart pointers or stack-allocated objects
- Efficient use of pass-by-reference for large objects to avoid unnecessary copying

### Lambdas

While the current implementation doesn't extensively use lambdas, they could be incorporated in several ways to enhance the code:

- Event handling in the main game loop
- Custom sorting or filtering of game objects
- Implementing game logic in a more functional style

Example of potential lambda use in event handling:

auto handleKeyPress = [&sokoban](sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::W: sokoban.movePlayer(SB::Direction::Up); break;
        case sf::Keyboard::S: sokoban.movePlayer(SB::Direction::Down); break;
        case sf::Keyboard::A: sokoban.movePlayer(SB::Direction::Left); break;
        case sf::Keyboard::D: sokoban.movePlayer(SB::Direction::Right); break;
    }
};

### Issues
None

### Extra Credit
1.Added time on the Window in MM:SS fromat
2.User interaction
    closes the window on pressing the 'C' key.


## Acknowledgements

1.SFML Document
2.ps4a pdf from BlackBoard

Kenney Sokoban Pack (CC0): https://kenney.nl/assets/sokoban
