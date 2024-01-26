#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>


using namespace std;

struct BST
{
  int key;
  BST *leftChild = NULL;
  BST *rightChild = NULL;

};

struct linkedListNode
{
    int key;
    struct linkedListNode* next;
};

struct node
{
    int key;
    struct node* next;
    linkedListNode* head = NULL;
    BST* root = NULL;
};


class HashTable
{


    int tableSize;
      // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    node* *table2;

    node* createNode(int key, node* next);
    linkedListNode* createNodeLL(int key, linkedListNode* next);
    BST* createNodeBST(int key, BST* leftChild, BST* rightChild);

  public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    /*
    bool insertItem(int key);

    node* searchItem(int key);
    */



    // hash function to map values to key
    unsigned int hashFunction(int key);
    unsigned int hashFunctionPrime(int key);

    //LINKED LIST
    void printTableLL();
    node* chainingLinkedListInsert(int key);
    node* chainingLinkedListInsertPrime(int key);
    int chainingLinkedListSearch(int key);
    int chainingLinkedListSearchPrime(int key);
    bool chainingLinkedListDelete(int key);
    bool chainingLinkedListDeletePrime(int key);

    //BINARY SEARCH TREE
    void printTreeBST();
    node* chainingBSTInsert(int key);
    node* chainingBSTInsertPrime(int key);
    bool chainingBSTSearch(int key);
    bool chainingBSTSearchPrime(int key);
    bool chainingBSTDelete(int key);
    bool chainingBSTDeletePrime(int key);


    //LINEAR PROBE
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
