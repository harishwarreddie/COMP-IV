# PS6: RandWriter

## Contact
Name: Harishwar Reddy Erri
Section: 202
Time to Complete: 4hrs


## Description
    The RandWriter is a sophisticated text generation library that leverages Markov chain algorithms to create probabilistic text based on an input corpus. By analyzing the statistical relationships between k-length character sequences (k-grams), this project enables dynamic and context-aware text generation.
    It features probabilistic text generation, flexible k-gram order, and circular text handling, implementing wrap-around logic for comprehensive sequence analysis.
    The library uses weighted probability distribution for random character selection, ensuring robust error checking and handling mechanisms. The core algorithm builds a frequency table during initialization, mapping k-grams to their potential subsequent characters, while the generate method constructs new text sequences, maintaining statistical fidelity to the original corpus. This project can be applied in various use cases such as creative writing assistance, text completion and prediction, linguistic pattern analysis, procedural content generation, and experimental natural language processing. The RandWriter effectively addresses technical challenges like circular text processing and maintaining contextual coherence, showcasing advanced algorithm design and probabilistic modeling techniques developed in C++.

### Features

The RandWriter class implements a Markov chain text generator with the following key features:

1.K-gram-based Frequency Analysis:
    The constructor builds a frequency table (freqTable) that maps k-grams to their following characters and their frequencies.
    It handles circular text by extending the input text with its first k-1 characters, ensuring all possible k-grams are captured.

2.Flexible K-gram Order:
    The class supports variable k-gram lengths, allowing for different levels of context in text generation.
    The k-gram length is set during object construction and used consistently throughout the class.

3.Random Text Generation:
    The generate method produces text of a specified length based on the Markov chain model.
    It starts with an initial k-gram and iteratively adds characters based on the probabilistic model.

4.Probabilistic Character Selection:
    The kRand method selects the next character based on the frequency distribution of characters following a given k-gram.
    It uses a uniform random distribution to ensure selections are weighted according to their frequencies.

5.Circular Text Handling:
    The class treats the input text as circular, allowing k-grams to wrap around from the end to the beginning of the text.
    This feature is crucial for maintaining consistent probability distributions for all k-grams.

6.Frequency Querying:
    The freq method allows querying the frequency of a specific k-gram or a k-gram followed by a specific character.
    This feature is useful for analysis and debugging purposes.

7.Error Handling and Input Validation:
    The class includes robust error checking, throwing exceptions for invalid inputs (e.g., k-grams of incorrect length).
    It handles edge cases, such as k-grams not found in the frequency table, by using fallback mechanisms.

8.Random Number Generation:
    The class uses C++'s random number generation facilities (std::random_device and std::mt19937) for high-quality randomness.

9.Efficient Data Structures:
    Utilizes std::unordered_map for O(1) average-case lookup time in the frequency table.

10.Customizable Text Generation:
    The generate method allows specifying both the initial k-gram and the desired length of the generated text.

11.Order Retrieval:
    The orderK method provides access to the k-gram length used by the model.

### Testing

The following are my test cases:
    1.TestInvalidKGram:
        Verifies that freq throws an exception for invalid k-grams; passes.
    
    2.TestValidKGram:
        Ensures freq works without exceptions for valid k-grams; passes.

    3.TestFrequencyOfKGram:
        Checks if freq correctly computes k-gram frequency; passes.

    4.TestGenerateText:
        Confirms generate produces non-empty text; passes.

    5.TestGenerateTextLength:
        Validates that generate produces text of the specified length; passes.

    6.TestGenerateIncorrectLength:
        Ensures generate handles large requested lengths accurately; passes.

    7.TestGenerateStartsWithCorrectKGram:
        Verifies that generate starts text with the correct k-gram; passes.

### Lambda

Lambda Functions
    While this implementation of RandWriter does not explicitly use lambda functions, some constructs might resemble them or could be substituted with lambdas for better modularity. Here are key areas to note:

    1.Loop Logic Inside kRand:
        The traversal of the frequency map in kRand could be replaced with a lambda if desired, to encapsulate the logic of reducing the random threshold r.
        
        for (const auto& pair : it->second) {
        r -= pair.second;
        if (r <= 0) {
            return pair.first;
        }
        }
    This code fragment iterates through a map and reduces the value r based on frequency counts until it identifies the corresponding character. While not implemented as a lambda, you could replace this with a lambda function that encapsulates the comparison logic for better clarity.

    2.Use of std::map and std::for_each: The loops in freq and generate methods manually aggregate or manipulate elements of a container. If needed, you could refactor parts of these into lambda functions combined with algorithms like std::for_each or std::accumulate.

    3.Error Handling and Fallback Strategy in generate: The fallback logic for selecting a random character in generate could be refactored into a lambda function for better readability. This would abstract the fallback strategy:

        auto fallbackChar = [&]() -> char {
            return inputText[rng() % inputText.size()];
        };

### Issues
    None

### Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
    1. ps6.pdf from Black Board.
