# PS2: Pentaflake

## Contact
Name: Harishwar Reddy Erri
Section: 202

Partner Name: -
Partner Section: -

Time to Complete: 5.5hrs


## Description

This program generates and displays a Pentaflake fractal, a geometric figure composed of pentagons in a recursive pattern.
The fractal is created using the SFML (Simple and Fast Multimedia Library) for graphics and audio.
The fractal begins with a central pentagon, and smaller pentagons are recursively added around it to form a symmetric, snowflake-like pattern.
The program also includes interactive features for rotating the fractal in both clockwise and counterclockwise directions and zooming in and out.
Additionally, background audio plays as soon as the window opens, enhancing the user experience.

The main components of the program are:
    - PentaflakeDrawer class: Handles the creation, drawing, and manipulation of the fractal.
    - main function: Sets up the application window and manages the main event loop.

### Features

    a) Fractal Generation:
        - Creates a pentaflake fractal based on user-specified base size and recursion levels.
        - Uses a color gradient to visually distinguish different levels of the fractal.
        - scaleFactor is calculated using the golden ratio, which determines the size reduction for child pentagons.
        - outerRadius is the distance from the center to a vertex of the parent pentagon.
        - innerOffset is the distance from the center to a vertex of a child pentagon.
        - The loop creates 5 child pentagons, positioned around the parent pentagon.
        - angle determines the rotation for each child pentagon.
        - offsetX and offsetY calculate the position of each child pentagon relative to the parent.
        - rotatedX and rotatedY apply an additional rotation to the entire structure.

    b) Rotation:
        - Clockwise rotation (R key)
        - Counter-clockwise rotation (L key)
        - X-axis rotation (X key)
        - Y-axis rotation (Y key)

    c) Zooming:
        - Zoom in (Q key)
        - Zoom out (W key)
        
    d) Audio Feedback:
        - Plays different background music based on the fractal's state (normal, rotating clockwise, or rotating counter-clockwise).
        - Normal state: normal.ogg
        - Clockwise rotation (R key): RR.ogg
        - Counter-clockwise rotation (L key): LR.ogg

    e) Reset Function:
        - Resets all transformations and rotations to their initial state (O key).
        
    f) Real-time Updates:
        - Continuously updates the fractal's state and redraw it for smooth animations.

### Issues
    none

### Extra Credit

The program includes several advanced features that could be considered extra credit:
    a) 3D-like Rotations:
        - Implements X and Y axis rotations to create a 3D-like effect.

    b) Color Interpolation:
        - Uses HSL color space for smooth color transitions between fractal levels.

    c) Audio Integration:
        - Incorporates background music that changes based on the fractal's rotation state.

    d) Smooth Animations:
        - Implements delta time-based updates for consistent animation speeds across different systems.

## changes

    - Improved the child pentagon placement 
    - Improved the Rotation features
    - Improved the color interpolation feature
    - Added a reset function
    - Improved the audio integration feature
    - Improved the zooming feature
    - Added a real-time update feature
    - Improved the audio feedback feature
    - Improved the 3D-like rotation feature


## Pair Programming

## Acknowledgements
1.SFML Documentation.
2.ps2.pdf from Blackboard
