#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>

using namespace std;

struct BST
{
  int key;
  BST *leftChild;
  BST *rightChild;

  BST() : leftChild(NULL), rightChild(NULL) {}
};

struct linkedListNode
{
  int key;
  struct linkedListNode *next;

  linkedListNode() : next(NULL) {}
};

struct node
{
  int key;
  struct node *next;
  linkedListNode *head;
  BST *root;

  node() : next(NULL), head(NULL), root(NULL) {}
};

class HashTable
{
  int tableSize;
  node **table;
  node **table2;

  node *createNode(int key, node *next);
  linkedListNode *createNodeLL(int key, linkedListNode *next);
  BST *createNodeBST(int key, BST *leftChild, BST *rightChild);

public:
  HashTable(int bsize);

  unsigned int hashFunction(int key);
  unsigned int hashFunctionPrime(int key);

  void printTableLL();
  node *chainingLinkedListInsert(int key);
  node *chainingLinkedListInsertPrime(int key);
  int chainingLinkedListSearch(int key);
  int chainingLinkedListSearchPrime(int key);
  bool chainingLinkedListDelete(int key);
  bool chainingLinkedListDeletePrime(int key);

  void printTreeBST();
  node *chainingBSTInsert(int key);
  node *chainingBSTInsertPrime(int key);
  bool chainingBSTSearch(int key);
  bool chainingBSTSearchPrime(int key);
  bool chainingBSTDelete(int key);
  bool chainingBSTDeletePrime(int key);

  void printProbeTable();
  int linearProbeInsert(int key);
  int linearProbeInsertPrime(int key);
  int linearProbeSearch(int key);
  int linearProbeSearchPrime(int key);
  bool linearProbeDelete(int key);
  bool linearProbeDeletePrime(int key);

  void printCuckooTables();
  int cuckooHashingInsert(int key);
  int cuckooHashingSearch(int key);
  bool cuckooHashingDelete(int key);
};

#endif