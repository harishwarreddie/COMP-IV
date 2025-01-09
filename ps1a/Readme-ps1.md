## contact
Name: Harishwar Reddy Erri
Section: 202
Time to Complete: 4.5 hours

## Description

1.Representation and Choice of LFSR
    The FibLFSR (Fibonacci Linear Feedback Shift Register) class uses a 16-bit string as its internal register, representing the state of the LFSR. This specific implementation applies bitwise XOR operations at positions 0, 2, 3, and 5 of the register, which dictate the LFSR’s feedback mechanism. The choice of these specific tap positions is common for creating effective pseudo-random sequences and is selected to ensure good randomness while keeping the implementation straightforward.

2.Description of Tests
    
    The tests for the FibLFSR class check key functionalities:
    The step function is tested to verify that it correctly generates a new bit based on the defined feedback taps and updates the register.
    The generate function is tested to ensure it accurately produces a sequence of bits by calling step repeatedly.
    Additional tests confirm that the initial seed length and format are validated to contain exactly 16 binary characters (0s and 1s).

### Features

1.FibLFSR Class:
    Seed Initialization and Validation: The constructor of the FibLFSR class takes a 16-bit binary string (std::string seed) as input. It validates that the seed is exactly 16 bits long and contains only '0' and '1' characters. If the seed does not meet these requirements, it throws an exception, ensuring the LFSR is always initialized in a valid state.

2.Step Function:
    Single-bit Generation and State Update: The step function generates a single new bit based on XOR operations across specific bits in the register (positions 0, 2, 3, and 5). This new bit is added to the end of the register string, while the first bit is removed, simulating a shift operation. This function returns the generated bit and updates the internal state, advancing the LFSR by one step.

3.Generate Function:
    Multiple-bit Sequence Generation: The generate function produces a sequence of bits of length k by calling the step function k times in a loop. It shifts each generated bit into a result variable, building a binary sequence over multiple steps, which is then returned as an integer. This allows users to generate arbitrary-length sequences from the LFSR.

4.Overloaded Output Operator:
    Display of LFSR State: An overloaded operator<< allows direct output of the LFSR’s current state through std::cout or other output streams. This feature provides a convenient way to visualize the register’s binary state at any point during its operation.


### Issues
none
### Changes 

1. Changed the functionality of the complete code and the working of the code which made me realize where the errors were and gave me a complete different approach than my previous one.
2. I made few changes to the FibLFSR.cpp file and gave a complete different input and made it work and also, I have tried different inputs and outputs to verify the functioning of the code.
3. I used generate function which I did not save previously.
### Tests

1.test_constructor:
    This test case verifies the correct initialization of the FibLFSR class with a given seed. It creates an FibLFSR instance with a predefined seed and immediately calls generate(5), checking that the generated sequence matches the expected output (3 in this case). This ensures the constructor correctly sets up the initial state.

2.test_step:
    This test case checks the step function, which generates a new bit and shifts the internal register. It calls step multiple times in succession and checks the output against expected values (0, 0, 0, and 1). This verifies that each step generates the correct bit and updates the internal state accurately.

3.test_generate:
    This test case evaluates the generate function, which produces a sequence of bits. The function is called three times with a parameter of 5 (to generate a 5-bit sequence), and each result is compared to the expected values (3, 6, and 14). This checks that generate accurately produces multiple sequences based on consecutive states.

4.test_stream_operator:
    This test case verifies the overloaded operator<< for outputting the current state of the FibLFSR instance. By streaming flfsr into an ostringstream, it confirms that the initial state is correctly represented as a string ("1011011000110110"). This ensures that the stream operator outputs the LFSR’s binary state accurately.

### Extra Credit
none

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
1.Took the reference of the ps1a.pdf from blackboard