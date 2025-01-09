# PS1: PhotoMagic

## Contact
Name: Harishwar Reddy Erri
Email: HarishwarReddy_Erri@student.uml.edu
ID: 02148304
Section: 202
Time to Complete: 8hrs

## Description
    To encrypt a given image using a Linear feedback shift register.
    I managed to do so by using the FibLFSR class and generate() function in order to return an integer unique to the original seed and tap point that specified.
    Then this integer with rgb values of each pixel in the source image I used to run an XOR operation to produce a pixel that is encrypted or     decrypted based on the original image.
    Then added the Alphanumeric Values to Encrypt and Decrypt the input file.

### Features
    1.The step() function takes one step of the LFSR, which is a crucial component in pseudo-random number generation. Generally, the operation  involves shifting the bits in a register and updating them according to certain feedback rules. Here is what may happen in this function:
    Shifts in the bits: The string rs that represents the register is left or right shifted by one bit.
    Feedback computation: The feedback is typically computed as the result of a logical XOR of some bits in the register, often the most left, combined with other chosen bits.
    Updates the register: The calculated parity bit is inserted into the register at the position where the bit was shifted out.
    The return function will most probably return the feedback bit: a or 1.

    2.The function generate(int k) generates a pseudorandom number over k steps. Here is one possible implementation of the function.
    It loops over k number of steps and in each step, it calls the function step():
    Accumulator result: It forms a k-bit number by concatenating the output bits from each call to step().
    Returns the generated number: The result of k steps is returned as an integer; it is a pseudo-random number generated from the LFSR.

    3.This operator << overloads to enable the FibLFSR object to be outputted with std::ostream. This is used to display the current state of LFSR; probably the rs string holding the bits in the register.
    Takes an ostream and a FibLFSR object: The function takes the output stream out and a reference to the FibLFSR object lfsr.
    Outputs the state: It writes the internal state of lfsr (probably rs) to the stream.
    Returns stream: It returns the modified stream for the chaining of output operations.

    4.By using the command ./PhotoMagic input-file.png output-file.png <seed>/Aplhanumeric value, we get the out where the encryption is done in the image.

    5.Encryption behaviour as follows:
    The transform function performs the encryption on the image through the lfsr object. An encryption is based on LFSR would XOR the pixel values of the image with bits generated from the LFSR. It modifies every pixel's RGB value to encode the image into actually scrambling it into the encrypted version.

    6.By using the command ./PhotoMagic output-file.png input-file.png <seed>/Aplhanumeric value, we get the out where the Decryption is done in the image.

    7.Decryption behaviour as follows:
    Because of the LFSR encryption is symmetric, The same seed, BSeed, and LFSR will work to decrypt the image. This is because reapplying the same transform function with the same seed should revert the encrypted image back to its original form, since XORing the pixel values twice with the same random sequence restores the original values.

### Issues
    No Issues.

### Tests
    1.BOOST_AUTO_TEST_CASE(test_operator_output):
    This macro defines a new test case named "test_operator_output".
    FibLFSR lfsr("1011011000110110");
    Instantiates an object of class FibLFSR (some sort of Fibonacci Linear Feedback Shift Register) initialized in the state "1011011000110110".
    std::ostringstream oss;
    Creates an output string stream object. It will serve to capture the output of the LFSR.

    2.BOOST_AUTO_TEST_CASE(test_generate):
    This macro defines a new test case named "test_generate".
    FibLFSR lfsr("1011011000110110");
    Creates an instance of the FibLFSR class with an initial state of "1011011000110110".
    BOOST_CHECK_EQUAL(lfsr.generate(5), 3);
    The following line is testing the method generate of the class FibLFSR :
    It calls the method lfsr.generate(5); probably generating 5 bits of the LFSR.
    The expected value to be returned is 3 (in decimal).
    As explained in the comment, this expected value was changed because of the usage of a new configuration of taps for the LFSR.
    BOOST_CHECK_EQUAL(lfsr.generate(5), 6);
    This line runs yet another check on the generate method:
    It once more calls lfsr.generate(5) to generate another 5 bits.
    This time, its expecting 6 (in decimal) as a result.

    3.BOOST_AUTO_TEST_CASE(test_multiple_steps):
    This macro defines a new test case named "test_multiple_steps".
    FibLFSR lfsr("0110100001100110");:
    Instantiates a FibLFSR object, whose initial state is set to "0110100001100110".
    BOOST_CHECK_EQUAL(lfsr.generate(7), 67);:
    This line is testing the generate method of the FibLFSR class:
    It invokes lfsr.generate(7), generating 7 bits from the LFSR.
    The expected output value should be 67 (in base 10).
    The comment indicates that this expected value was modified in order to reflect new tap bits in the configuration of the LFSR.
    BOOST_CHECK_EQUAL(lfsr.generate(9), 24):
    This tests the generate method:
    It runs lfsr.generate(9) to generate 9 bits.
    The expected value is 24, in decimal
    The comment again says this value was adjusted for the new tap configuration.
    So on remaining test cases.

### Extra Credit
    Added the extra credit by including the Alphanumeric values to Encrypt and Decrypt the input-file.png
    the following command is to Encrypt and Decrypt the input-file.png:
    ./PhotoMagic input-file.png output-file.png <Alphanumeric Value>.
    The function alphanumericToBinary() converts an alphanumeric string (ANSeed) into its binary representation and stores it in BSeed. Thus, the starting point is from here: at which BSeed holds the binary string derived from ANSeed.
    ANSeed, as the alphanumeric input, is converted to a binary string BSeed.
    If less than 16 characters in length, the binary string is doubled until it is at least 16 characters long.
    Once it is ensured that BSeed is at least 16 characters long, it is then truncated to exactly 16 characters.

## Acknowledgements
    1.Professor PDF ps1b.pdf
    2.SFML Document