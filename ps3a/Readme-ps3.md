# PS3: N-Body Simulation

## Contact
Name: Harishwar Reddy Erri
Section: 202 
Time to Complete: 6hrs


## Description

    This project is a solar system simulation using SFML (Simple and Fast Multimedia Library) in C++. It creates a graphical representation of celestial bodies orbiting in space, with the following key components:

        1.A main window displaying the simulation.
        2.A background image representing space.
        3.Multiple celestial bodies (planets, stars, etc.) loaded from a file.
        4.Background music that can be toggled on/off.
        The simulation reads celestial body data from a text file, initializes the bodies with their properties (position, velocity, mass, texture), and renders them on the screen. Users can interact with the simulation by closing the window or toggling the background music.

### Features

    1.Dynamic Celestial Body Simulation:
        The program can handle an arbitrary number of celestial bodies, each with its own mass, position, and velocity.
    
    2.Graphical Representation:
        Using SFML, the simulation provides a visual representation of the celestial bodies and their movements.
    
    3.Background Scenery:
        The simulation includes a customizable background image to enhance the visual experience.
    
    4.Audio Integration:
        Background ambient music can be added to the simulation, creating a more immersive experience.
    
    5.User Interaction:
        The simulation window can be closed by clicking the close button or pressing the ESC key.
        Background music can be toggled on/off by pressing the 'M' key.
    
    6.Scalable Display:
        The simulation adjusts the display of celestial bodies based on the universe's size and the window dimensions.
    
    7.File Input:
        The initial state of the universe is read from a configuration file, allowing for easy setup of different scenarios.

### Memory
The project uses a mix of stack-allocated objects and dynamically allocated objects:

    1.Stack-allocated Objects:
    Objects like sf::RenderWindow, sf::Texture, sf::Sprite, and sf::Music are created on the stack, allowing for automatic memory management.
    
    2.Dynamically Allocated Objects:
    CelestialBody objects are dynamically allocated using new and stored as pointers in the Universe class. This allows for flexibility in the number of bodies and easier management of their lifetimes.

    3.Smart Pointers:
    The code uses std::unique_ptr for managing dynamically allocated CelestialBody objects, ensuring proper memory management and preventing memory leaks.

    4.RAII Principles:
    The use of C++ standard containers (std::vector) and SFML resource classes (sf::Texture, sf::Sprite, sf::Music) adheres to RAII principles, automatically managing resource lifetimes.
    
    5.Custom Destructor:
    The Universe class has a custom destructor to ensure proper cleanup of resources, particularly for the SFML Music object.
    
    6.Resource Management:
    SFML resources like textures and music are managed by SFML's internal reference counting system, which helps prevent resource leaks.5.

### Issues
no issues

## changes 

    - updated the code to use a more efficient data structure for storing celestial bodies
    - fixed a bug that caused the simulation 
    - updated the code to use a more modern C++ style
    - added a new feature to the simulation: the ability to add a new celestial body to the universe

### Extra Credit
    
    1.Audio Integration:
        The addition of background music that can be toggled on and off adds an extra dimension to the user experience.

    2.User Interaction:
        The ability to close the simulation with the ESC key and toggle music demonstrates attention to user experience.
     
    3.Scalable Graphics:
        The simulation adjusts the size and position of celestial bodies based on the universe size and window dimensions, allowing for flexibility in display.
    
    4.Error Handling:
        The code includes error checking and reporting for file operations and asset loading, improving robustness.
    
    5.Modular Design:
        The separation of CelestialBody and Universe classes allows for easy expansion and modification of the simulation.
    
    
## Acknowledgements
1.SFML Documentation
2.ps3a.pdf from BlackBoard