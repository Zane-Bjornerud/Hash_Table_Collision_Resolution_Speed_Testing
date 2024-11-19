Hash Table Implementation and Performance Analysis
This project implements and analyzes different hash table collision resolution methods, comparing their performance across various load factors. The implementation includes four different collision resolution strategies and provides detailed timing analysis for basic operations.
Features
Collision Resolution Methods

Chaining with Linked List: Traditional chaining where collisions are handled by linking elements in a linked list
Chaining with BST: Modified chaining using Binary Search Trees for potentially better search performance
Linear Probing: Open addressing method that linearly probes for the next available slot
Cuckoo Hashing: Implementation using two hash functions to resolve collisions

Performance Analysis

Measures performance of Insert, Search, and Delete operations
Tests each method across multiple load factors (0.1, 0.2, 0.5, 0.7, 0.9)
Provides detailed timing analysis including:

Individual operation times
Total execution times
Rankings for each operation type
Comparative analysis across methods



Technical Details

Table size: 10009 (prime number)
Two hash functions:

Primary: key % tableSize
Secondary: floor(key / tableSize) % tableSize


All timings measured in seconds with microsecond precision
Averaged over 100 operations for statistical significance

Installation
Prerequisites

C++ compiler with C++98/C++03 support
Make (optional, for build automation)
Input data file (CSV format)

Building from Source

Clone the repository:

bashCopygit clone https://github.com/yourusername/hash-table-analysis.git
cd hash-table-analysis

Compile the source:

bashCopyg++ -o hashtable main.cpp hashTable.cpp
Usage
Running the Program

Ensure you have a CSV file with comma-separated integers for testing
Run the program:

bashCopy./hashtable input.csv
Sample Input File Format
Copy100,205,310,415,520,625,730,835,940,1045,...
Sample Output
The program will display:

Performance results for each load factor
Timing analysis for each operation type
Rankings of methods for insert, search, and delete operations
Total execution times for comparison

Example output:
Copy=========== Results for Load Factor 0.90000000 ===========

All times are in seconds, averaged over 100 operations
Clock resolution: 0.00000100 seconds
CLOCKS_PER_SEC: 1000000

Method               Insert(sec)         Search(sec)         Delete(sec)          Total(sec)
----------------------------------------------------------------------------------------------------
Linear-Probing      0.00000097         0.00000090         0.00000092         0.00000279
----------------------------------------------------------------------------------------------------
...

FASTEST FOR EACH OPERATION:

INSERT Rankings:
--------------------------------------------------
#1: Linear-Probing      0.00000097 sec
...
Performance Considerations

Load factors significantly impact performance
Different methods excel in different scenarios:

Linear Probing: Generally fastest for low load factors
BST Chaining: Good for search operations
Cuckoo Hashing: Consistent performance across operations
Linked List Chaining: Simple but slower at high load factors



Contributing
Feel free to fork the repository and submit pull requests. For major changes, please open an issue first to discuss the proposed change.

Authors

Zane Bjornerud
