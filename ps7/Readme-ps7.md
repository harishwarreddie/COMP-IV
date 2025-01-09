# PS7: Kronos Log Parsing

## Contact
Name: Harishwar Reddy Erri
Section: 202 
Time to Complete: 6hrs


## Description

This C++ program is a sophisticated log file analyzer designed to process and interpret device boot logs. Its primary function is to parse through a given log file, identify boot events, calculate boot durations, and generate a detailed report. The program is particularly useful for system administrators and developers who need to monitor and analyze the boot performance of devices.
    Key aspects of the program include:
        1.Utilization of the Boost library for advanced regular expression matching and precise time handling.
        2.Ability to process large log files efficiently.
        3.Generation of a human-readable report that clearly outlines each boot attempt and its outcome.

### Features

1.Log File Processing:
    Accepts a log file name as a command-line argument
    Reads the log file line by line, ensuring efficient memory usage even for large files

2.Boot Event Detection:
    Identifies the start of a boot process using a specific regex pattern
    Detects successful boot completions using another regex pattern
    Handles multiple boot attempts within the same log file

3.Time Calculation:
    Parses timestamps from log entries using Boost's time functions
    Calculates the duration of successful boots with millisecond precision

4.Incomplete Boot Handling:
    Detects and reports boot attempts that did not complete successfully
    Provides clear indication of incomplete boots in the output report

5.Formatted Report Generation:
    Creates a well-structured report file with a ".rpt" extension
    Presents each boot attempt in a clear, easy-to-read format
I   ncludes line numbers and file names for easy reference back to the original log

6.Error Handling:
    Manages file opening errors for both input and output files
    Handles regex compilation errors, ensuring robustness    

### Approach

The program follows a systematic approach to analyze the log file:
    Command-Line Argument Handling:
        Checks for the correct number of arguments (expecting the log file name)
        Exits with an error message if the argument is missing
    
    File Operations:
        Opens the specified log file for reading
        Creates a new file for the report, appending ".rpt" to the original file name
        Implements error checking for file operations
        
    Regular Expression Compilation:
        Defines two regex patterns: one for boot start and another for boot completion
        Uses try-catch block to handle potential regex compilation errors
    
    Log File Processing:
        Reads the log file line by line
        For each line, attempts to match it against the boot start and completion patterns
    
    Boot Event Tracking:
        Maintains a state (isBooting) to track whether a boot process is in progress
        Creates a BootService struct to store information about each boot attempt
    
    Time Parsing and Calculation:
        Extracts timestamps from matched log entries
        Uses Boost's time functions to parse these timestamps and calculate durations
    
    Report Generation:
        Writes formatted information about each boot attempt to the report file
        Includes start time, end time (if completed), and duration for successful boots
        Marks incomplete boots with a distinct message
    
    Cleanup and Finalization:
        Handles the case of an incomplete boot at the end of the file
        Closes both input and output files properly

### Regex

The program relies heavily on two critical regular expressions:
    Boot Start Pattern:

        R"((.*): (\(log.c.166\) server started.*))"

        This pattern is designed to capture the timestamp and the server start message.
        The (.*) at the beginning captures the timestamp.
        The ($$log.c.166$$ server started.*) part identifies the specific log message indicating the start of a boot process.
        The use of raw string literal (R"...") allows for easier handling of backslashes in the regex.

    Boot Completion Pattern:

        "(.*)\\.\\d*:INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080.*"

        This pattern identifies the successful completion of the boot process.
        The (.*) at the beginning captures the timestamp.
        The \\.\\d* matches a decimal point followed by any number of digits, which is part of the timestamp format.
        The rest of the pattern matches the specific log message indicating a successful boot completion.

### Issues
none

### Extra Credit
    Yes, I did Extra Credit i.e,
    I have added the summery header in which it displays the following 
    - InTouch log file Information
    - Lines Scanned
    - Device boot count:
        Initiated
        Completed



## Acknowledgements

    1.ps7.pdf from the Blackboard
