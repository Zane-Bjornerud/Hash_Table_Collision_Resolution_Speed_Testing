#include "hashTable.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct PerformanceResult
{
  string method;
  double loadFactor;
  double insertTime;
  double searchTime;
  double deleteTime;
  double totalTime;

  PerformanceResult(string m, double lf, double it, double st, double dt)
      : method(m), loadFactor(lf), insertTime(it), searchTime(st), deleteTime(dt)
  {
    totalTime = insertTime + searchTime + deleteTime;
  }
};

// Comparison function for sorting
bool compareResults(const PerformanceResult &a, const PerformanceResult &b)
{
  return a.totalTime < b.totalTime;
}

// Function to load CSV data into a vector
vector<int> loadCSV(const string &filename)
{
  vector<int> numbers;
  ifstream file(filename);
  string value;

  if (!file.is_open())
  {
    cout << "Error: Could not open file " << filename << endl;
    return numbers;
  }

  while (getline(file, value, ','))
  {
    if (!value.empty())
    {
      numbers.push_back(stoi(value));
    }
  }

  file.close();
  return numbers;
}

// Test functions return PerformanceResult object
PerformanceResult testChainingLinkedList(HashTable &hash, vector<int> &data, double loadFactor, int tableSize)
{
  int insertCount = 0;
  int targetCount = static_cast<int>(tableSize * loadFactor);

  clock_t startTime, endTime;
  double insertTime = 0, searchTime = 0, deleteTime = 0;
  vector<int> insertedValues;

  // Insert phase
  for (size_t i = 0; i < data.size() && insertCount < targetCount; ++i)
  {
    startTime = clock();
    node *result = hash.chainingLinkedListInsert(data[i]);
    endTime = clock();
    if (result != NULL)
    {
      insertTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;
      insertCount++;
      insertedValues.push_back(data[i]);
    }
  }

  // Test operations
  int testCount = 0;
  while (testCount < 100 && !insertedValues.empty())
  {
    int testValue = insertedValues[rand() % insertedValues.size()];

    startTime = clock();
    hash.chainingLinkedListSearch(testValue);
    endTime = clock();
    searchTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;

    startTime = clock();
    hash.chainingLinkedListDelete(testValue);
    endTime = clock();
    deleteTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;

    hash.chainingLinkedListInsert(testValue);
    testCount++;
  }

  if (testCount > 0)
  {
    insertTime /= testCount;
    searchTime /= testCount;
    deleteTime /= testCount;
  }

  return PerformanceResult("Chaining-LinkedList", loadFactor, insertTime, searchTime, deleteTime);
}

PerformanceResult testChainingBST(HashTable &hash, vector<int> &data, double loadFactor, int tableSize)
{
  int insertCount = 0;
  int targetCount = static_cast<int>(tableSize * loadFactor);

  clock_t startTime, endTime;
  double insertTime = 0, searchTime = 0, deleteTime = 0;
  vector<int> insertedValues;

  for (size_t i = 0; i < data.size() && insertCount < targetCount; ++i)
  {
    startTime = clock();
    node *result = hash.chainingBSTInsert(data[i]);
    endTime = clock();
    if (result != NULL)
    {
      insertTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;
      insertCount++;
      insertedValues.push_back(data[i]);
    }
  }

  int testCount = 0;
  while (testCount < 100 && !insertedValues.empty())
  {
    int testValue = insertedValues[rand() % insertedValues.size()];

    startTime = clock();
    hash.chainingBSTSearch(testValue);
    endTime = clock();
    searchTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;

    startTime = clock();
    hash.chainingBSTDelete(testValue);
    endTime = clock();
    deleteTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;

    hash.chainingBSTInsert(testValue);
    testCount++;
  }

  if (testCount > 0)
  {
    insertTime /= testCount;
    searchTime /= testCount;
    deleteTime /= testCount;
  }

  return PerformanceResult("Chaining-BST", loadFactor, insertTime, searchTime, deleteTime);
}

PerformanceResult testLinearProbing(HashTable &hash, vector<int> &data, double loadFactor, int tableSize)
{
  int insertCount = 0;
  int targetCount = static_cast<int>(tableSize * loadFactor);

  clock_t startTime, endTime;
  double insertTime = 0, searchTime = 0, deleteTime = 0;
  vector<int> insertedValues;

  for (size_t i = 0; i < data.size() && insertCount < targetCount; ++i)
  {
    startTime = clock();
    int result = hash.linearProbeInsert(data[i]);
    endTime = clock();
    if (result == 1)
    {
      insertTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;
      insertCount++;
      insertedValues.push_back(data[i]);
    }
  }

  int testCount = 0;
  while (testCount < 100 && !insertedValues.empty())
  {
    int testValue = insertedValues[rand() % insertedValues.size()];

    startTime = clock();
    hash.linearProbeSearch(testValue);
    endTime = clock();
    searchTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;

    startTime = clock();
    hash.linearProbeDelete(testValue);
    endTime = clock();
    deleteTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;

    hash.linearProbeInsert(testValue);
    testCount++;
  }

  if (testCount > 0)
  {
    insertTime /= testCount;
    searchTime /= testCount;
    deleteTime /= testCount;
  }

  return PerformanceResult("Linear-Probing", loadFactor, insertTime, searchTime, deleteTime);
}

PerformanceResult testCuckooHashing(HashTable &hash, vector<int> &data, double loadFactor, int tableSize)
{
  int insertCount = 0;
  int targetCount = static_cast<int>(tableSize * loadFactor);

  clock_t startTime, endTime;
  double insertTime = 0, searchTime = 0, deleteTime = 0;
  vector<int> insertedValues;

  for (size_t i = 0; i < data.size() && insertCount < targetCount; ++i)
  {
    startTime = clock();
    int result = hash.cuckooHashingInsert(data[i]);
    endTime = clock();
    if (result >= 0)
    {
      insertTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;
      insertCount++;
      insertedValues.push_back(data[i]);
    }
  }

  int testCount = 0;
  while (testCount < 100 && !insertedValues.empty())
  {
    int testValue = insertedValues[rand() % insertedValues.size()];

    startTime = clock();
    hash.cuckooHashingSearch(testValue);
    endTime = clock();
    searchTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;

    startTime = clock();
    hash.cuckooHashingDelete(testValue);
    endTime = clock();
    deleteTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;

    hash.cuckooHashingInsert(testValue);
    testCount++;
  }

  if (testCount > 0)
  {
    insertTime /= testCount;
    searchTime /= testCount;
    deleteTime /= testCount;
  }

  return PerformanceResult("Cuckoo-Hashing", loadFactor, insertTime, searchTime, deleteTime);
}

// Add these comparison functions at the top of the file, before printResults
bool compareByInsert(const PerformanceResult &a, const PerformanceResult &b)
{
  return a.insertTime < b.insertTime;
}

bool compareBySearch(const PerformanceResult &a, const PerformanceResult &b)
{
  return a.searchTime < b.searchTime;
}

bool compareByDelete(const PerformanceResult &a, const PerformanceResult &b)
{
  return a.deleteTime < b.deleteTime;
}

void printResults(vector<PerformanceResult> &results, double loadFactor)
{
  cout << "\n=========== Results for Load Factor " << fixed << setprecision(8) << loadFactor << " ===========\n"
       << endl;
  cout << "All times are in seconds, averaged over 100 operations" << endl;
  cout << "Clock resolution: " << (1.0 / CLOCKS_PER_SEC) << " seconds" << endl;
  cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl
       << endl;

  // Create vectors for sorting by each operation
  vector<PerformanceResult> insertSort = results;
  vector<PerformanceResult> searchSort = results;
  vector<PerformanceResult> deleteSort = results;

  // Sort by each operation type using traditional comparison functions
  sort(insertSort.begin(), insertSort.end(), compareByInsert);
  sort(searchSort.begin(), searchSort.end(), compareBySearch);
  sort(deleteSort.begin(), deleteSort.end(), compareByDelete);
  sort(results.begin(), results.end(), compareResults); // Sort original by total time

  // Print main results table
  cout << left << setw(20) << "Method"
       << right
       << setw(20) << "Insert(sec)"
       << setw(20) << "Search(sec)"
       << setw(20) << "Delete(sec)"
       << setw(20) << "Total(sec)"
       << endl;

  cout << string(100, '-') << endl;

  // Calculate totals
  double totalInsert = 0, totalSearch = 0, totalDelete = 0, grandTotal = 0;

  for (size_t i = 0; i < results.size(); i++)
  {
    cout << left << setw(20) << results[i].method
         << right << fixed << setprecision(8)
         << setw(20) << results[i].insertTime
         << setw(20) << results[i].searchTime
         << setw(20) << results[i].deleteTime
         << setw(20) << results[i].totalTime
         << endl;

    totalInsert += results[i].insertTime;
    totalSearch += results[i].searchTime;
    totalDelete += results[i].deleteTime;
    grandTotal += results[i].totalTime;

    cout << string(100, '-') << endl;
  }

  // Print totals
  cout << left << setw(20) << "TOTAL TIME:"
       << right << fixed << setprecision(8)
       << setw(20) << totalInsert
       << setw(20) << totalSearch
       << setw(20) << totalDelete
       << setw(20) << grandTotal
       << "\n\n";

  // Print rankings for each operation
  cout << "\nFASTEST FOR EACH OPERATION:\n"
       << endl;

  cout << "INSERT Rankings:" << endl;
  cout << string(50, '-') << endl;
  for (size_t i = 0; i < insertSort.size(); i++)
  {
    cout << "#" << (i + 1) << ": " << left << setw(20) << insertSort[i].method
         << fixed << setprecision(8) << insertSort[i].insertTime << " sec" << endl;
  }

  cout << "\nSEARCH Rankings:" << endl;
  cout << string(50, '-') << endl;
  for (size_t i = 0; i < searchSort.size(); i++)
  {
    cout << "#" << (i + 1) << ": " << left << setw(20) << searchSort[i].method
         << fixed << setprecision(8) << searchSort[i].searchTime << " sec" << endl;
  }

  cout << "\nDELETE Rankings:" << endl;
  cout << string(50, '-') << endl;
  for (size_t i = 0; i < deleteSort.size(); i++)
  {
    cout << "#" << (i + 1) << ": " << left << setw(20) << deleteSort[i].method
         << fixed << setprecision(8) << deleteSort[i].deleteTime << " sec" << endl;
  }
  cout << endl;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " <input_file.csv>" << endl;
    return 1;
  }

  srand(time(NULL));

  vector<int> data = loadCSV(argv[1]);
  if (data.empty())
  {
    cout << "No data loaded from file." << endl;
    return 1;
  }

  cout << "Loaded " << data.size() << " numbers from CSV file." << endl;

  const int TABLE_SIZE = 10009;
  vector<double> loadFactors;
  loadFactors.push_back(0.1);
  loadFactors.push_back(0.2);
  loadFactors.push_back(0.5);
  loadFactors.push_back(0.7);
  loadFactors.push_back(0.9);

  // Test each load factor
  for (size_t i = 0; i < loadFactors.size(); i++)
  {
    vector<PerformanceResult> results;
    double loadFactor = loadFactors[i];

    HashTable hashLL(TABLE_SIZE);
    results.push_back(testChainingLinkedList(hashLL, data, loadFactor, TABLE_SIZE));

    HashTable hashBST(TABLE_SIZE);
    results.push_back(testChainingBST(hashBST, data, loadFactor, TABLE_SIZE));

    HashTable hashLP(TABLE_SIZE);
    results.push_back(testLinearProbing(hashLP, data, loadFactor, TABLE_SIZE));

    HashTable hashCuckoo(TABLE_SIZE);
    results.push_back(testCuckooHashing(hashCuckoo, data, loadFactor, TABLE_SIZE));

    printResults(results, loadFactor);
  }

  return 0;
}