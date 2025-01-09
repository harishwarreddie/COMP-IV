# PS5: DNA Alignment

## Contact
Name: Harishwar Reddy Erri
Section: 202
Time to Complete: 6 hours


## Description

The EDistance program computes the edit distance (also known as Levenshtein distance) between two strings and provides a detailed alignment showing how the strings differ.
The program allows you to compare two sequences of characters, determining the minimum number of operations (insertions, deletions, or substitutions) required to transform one string into another.  The core logic uses dynamic programming to build a table of optimal operations, ensuring an efficient solution to the problem. After calculating the edit distance, the program can output an alignment that shows how the two strings can be transformed into one another, with the corresponding operation (substitute, insert, delete) and the cost for each operation.

Key components of the project:

  Dynamic programming approach to calculate the minimum edit distance.
  A detailed alignment function to show how the strings can be transformed.
  Penalty functions for substitution operations (matching characters cost 0, mismatched characters cost 1).
  An easy-to-use interface for taking user input and displaying results.

### Features

1.Edit Distance Calculation:
  The program calculates the edit distance between two input strings using dynamic programming.
  Edit distance represents the minimum number of operations (insertions, deletions, or substitutions) needed to transform one string into another.

2.Alignment Generation:
  The program generates the alignment of the two strings, displaying the relationship between characters in a detailed format:
    0 for matches,
    1 for substitutions,
    2 for insertions or deletions.

3.Memory Usage Calculation:
  The calculateMemoryUsageMB method computes the memory used by the distance matrix in megabytes, helping assess the program's scalability for large strings.

4.Readable Output:
  The results include:
    The calculated edit distance.
    A detailed alignment showing matches and mismatches.
    Memory used in MB.
    Execution time in seconds.

5.Dynamic Memory Allocation:
  The program dynamically allocates memory for the distance matrix based on the input strings' lengths, ensuring efficient use of resources.

6.Scalable for Large Inputs:
  The use of calculateMemoryUsageMB provides insights into the scalability of the program for larger strings, and it effectively demonstrates memory-intensive behavior for analysis.

7.Efficient Minimum Calculation:
  A custom findMin method determines the smallest value among three options, which is central to the dynamic programming logic.

8.Custom Penalty Calculation:
  A lambda function in the computePenalty method computes the cost of substituting one character for another (0 if they are the same, 1 otherwise).

9.Performance Metrics:
  The program uses the SFML library's sf::Clock and sf::Time to measure and display execution time.

10.User Input Handling:
  The program accepts two strings from the user, processes them, and outputs the results interactively.

11.Memory Safety:
  The EDistance destructor ensures that all dynamically allocated memory is freed, preventing memory leaks.

12.Error Handling:
  If one or both input strings are empty, the program throws an exception to prevent undefined behavior.


### Testing

1.FIRST_TESTCASE:
  Checks: The computePenalty method correctly identifies when two characters are identical and assigns a penalty of 0.
  Reason: This method is a core part of the edit distance algorithm, and ensuring its correctness is critical for accurate distance computation.

2.SECOND_TESTCASE:
  Checks: The constructor throws an exception when one or both input strings are empty.
  Reason: Empty strings are invalid input for the edit distance algorithm. Validating that the class handles such cases gracefully ensures robustness.

3.THIRD_TESTCASE:
  Checks: The findMin static method returns the smallest of three integers.
  Reason: This method is repeatedly used in the dynamic programming matrix calculation. Its accuracy directly affects the final edit distance result.

4.FOURTH_TESTCASE:
  Checks: The calculateDistance method computes the correct edit distance between two strings.
  Reason: This is the primary functionality of the EDistance class. Testing both simple and non-trivial cases ensures that the implementation works across various scenarios.

## Analysis

When I run valgrind. 
ms_print massif.out.11320
--------------------------------------------------------------------------------
Command:            ./EDistance
Massif arguments:   (none)
ms_print arguments: massif.out.11320
--------------------------------------------------------------------------------


    KB
76.80^                                                                       #
     |                                                                      @#
     |                                                                  ::::@#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
   0 +----------------------------------------------------------------------->Mi
     0                                                                   2.568

Number of snapshots: 37                                                                  2.096

This is for fli8.txt

### Issues
None

### Example

--> The test case used is lastygaps9.txt
--> The input of that file is:
    
  atattataa
    
and the expected output is:
    
  atattat

The Output is:
Edit distance = 4
a a 0
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
a - 2
a - 2
Memory used = 0.000305176 MB
Execution time is 0.003336 seconds 

### Specs

Your Computer
Memory: 16GB DDR5
Processors: 13th Gen Intel(R) Core(TM) i5-13500H   2.60 GHz



### Runs
Fill in the table with the results of running your code on both your and your partner's computers.

| data file     | distance | memory (mb) | time (seconds) | partner time |
|---------------|----------|-------------|----------------|--------------|
|ecoli2500.txt  |  118     |    23.8609  |   0.096203     |      -       |
|ecoli5000.txt  |  160     |    95.4056  |   0.542043     |      -       |
|ecoli10000.txt |  223     |    381.546  |   1.675230     |      -       |
|ecoli20000.txt |  3135    |    1526.03  |   6.947500     |      -       |
|ecoli50000.txt |  Killed  |      -      |      -         |      -       |
|ecoli100000.txt|  Killed  |      -      |      -         |      -       |


Here is an example from another computer for some of the files.

| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |

### Time
Assume the two strings are the same length (M = N).  By applying the doubling method to the data points that you obtained, estimate the running time of yoru program in seconds as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle given the amount of memory available.

Provide a brief justification/explanation of how you applied the doubling method, and if you data seems not to work, describe what went wrong and use the sample data instead.
 - a = 9e-9
 - b = 2
 - largest N = 3098386

### Memory
Assume the two strings are the same length (M = N).  Look at your code and determine how much memory it requires as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle given the amount of memory available.
 - a = 24 bytes
 - b = 4 bytes
 - largest N ~ 23000

 Explanation:
 24 * N^2 = 12GB
 N ~ 23000

### Valgrind

It is error free and  the memory usage reported by valgrind almost matches the calculations in the previous section.

### Extra Credit

1. Used lambda expressions in min3 function and penalty function.
2. I implemented my own min3() which takes 3 arguments and returns the minimum.

## Pair Programming
If you worked with a partner, do you have any remarks on the pair programming method? E.g., how many times did you switch, what are the tradeoffs of driving vs. navigating, etc.?
None

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

--> ps5.pdf from the BlackBoard
