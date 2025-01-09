# PS3: N-Body Simulation

## Contact
Name: Harishwar Reddy Erri
Section: 202 
Time to Complete: 8hrs


## Description
This project implements an N-Body simulation of celestial bodies in a 2D universe.
The simulation uses the SFML library for graphics and audio, providing a visual representation of the gravitational interactions between multiple celestial bodies. The program reads initial conditions from standard input, simulates the motion of the bodies over time, and outputs the final state of the universe.
The simulation is based on Newton's laws of motion and universal gravitation, calculating the forces between all pairs of bodies and updating their positions and velocities accordingly.
The program uses a namespace NB to encapsulate the CelestialBody and Universe classes, providing a clean and organized structure.

### Features
1.N-Body Simulation:
    Accurately simulates the gravitational interactions between multiple celestial bodies.
2.Graphical Representation:
    Uses SFML to create a visual representation of the universe, with planets displayed as sprites.
3.Background Image:
    Includes a space background image to enhance the visual experience.
4.Audio Support:
    Incorporates background music that can be toggled on/off during the simulation.
5.Real-time Display:
    Shows the elapsed simulation time on the screen.
6.Customizable Simulation Parameters:
    Allows users to specify the total simulation time and time step via command-line arguments.
7.File I/O:
    Reads initial conditions from standard input and writes the final state to standard output.
8.Scalable Planet Sizes:
    Adjusts the size of planet sprites based on their mass.
9.Error Handling:
    Includes checks for file loading and command-line argument parsing.

### Memory
The project uses a mix of stack-allocated objects and dynamically allocated objects:
1.Stack-allocated Objects:
 Objects like sf::RenderWindow, sf::Texture, sf::Sprite, and sf::Music are created on the stack, allowing for automatic memory management.
2.Dynamically Allocated Objects:
 CelestialBody objects are dynamically allocated using new and stored as pointers in the Universe class. This allows for flexibility in the number of bodies and easier management of their lifetimes.
3.Manual Memory Management:
 The project does not use smart pointers, instead opting for manual memory management. The CelestialBody pointers are deleted in the main function after the simulation loop ends:
    for (auto BODY : universe.getBodies()) { delete BODY;}
4.Potential Improvement:
 The use of smart pointers (e.g., std::unique_ptr or std::shared_ptr) could enhance memory safety and reduce the risk of memory leaks, especially in cases where exceptions might be thrown before the manual cleanup occurs.
5.Resource Management:
 SFML resources like textures and music are managed by SFML's internal reference counting system, which helps prevent resource leaks.5.

### Issues
no issues

### Extra Credit
1.Background Image:
The simulation includes a background image to represent space, enhancing the visual appeal of the simulation.
2.Background Music:
The project incorporates background music that can be toggled on and off using the 'M' key.
3.User Interaction:
Music can be played or stopped by pressing the 'M' key, allowing user control over the audio.
4.Centered Sprites:
The sprites are centered on their positions, providing a more accurate representation of the celestial bodies' locations.

## Acknowledgements
1.SFML Documentation
2.ps3b.pdf from BlackBoard