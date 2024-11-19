// CPP program to implement hashing with chaining
#include <iostream>
#include "hashTable.hpp"
#include <cmath>

using namespace std;

node *HashTable::createNode(int key, node *next)
{
  node *nw = new node;
  nw->key = key;
  nw->next = next;
  // nw->numb = -1;
  return nw;
}

linkedListNode *HashTable::createNodeLL(int key, linkedListNode *next)
{
  linkedListNode *ll = new linkedListNode;
  ll->key = key;
  ll->next = next;
  return ll;
}

BST *HashTable::createNodeBST(int key, BST *leftChild, BST *rightChild)
{
  BST *newNode = new BST;
  newNode->key = key;
  newNode->leftChild = leftChild;
  newNode->rightChild = rightChild;
  return newNode;
}

HashTable::HashTable(int bsize)
{
  this->tableSize = bsize;
  table = new node *[tableSize];
  table2 = new node *[tableSize];
  for (int i = 0; i < bsize; i++)
  {
    table[i] = NULL;
    table2[i] = NULL;
  }
}

// function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
  return (key % tableSize);
}

unsigned int HashTable::hashFunctionPrime(int key)
{
  return ((int)floor(key / tableSize)) % tableSize;
}

// LINKED LIST

// function to display hash table
void HashTable::printTableLL()
{
  for (int i = 0; i < 100; i++)
  {
    cout << i << "|| ";
    if (table[i] == NULL)
    {
      cout << "NULL" << endl;
    }
    else
    {
      linkedListNode *temp = table[i]->head;
      while (temp != NULL)
      {
        cout << temp->key << " -> ";
        temp = temp->next;
      }
      cout << "NULL" << endl;
    }
  }
}

node *HashTable::chainingLinkedListInsert(int key)
{
  int index = 0;
  bool dupe = false;
  index = hashFunction(key);
  cout << index << endl;

  if (table[index] == NULL)
  {
    table[index] = createNode(key, NULL);
    table[index]->head = createNodeLL(key, NULL);
    // cout << "Inserted1";
    // return table[index];
  }
  else if (table[index] != NULL)
  {
    linkedListNode *ll = createNodeLL(key, NULL);
    if (table[index]->head == NULL)
    {
      table[index]->head = ll;
      // cout << "Inserted2";
      // return table[index];
    }
    else
    {
      linkedListNode *temp = table[index]->head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = ll;
      // cout << "Inserted3";
      // return table[index];
    }
  }
  return table[index];
}

node *HashTable::chainingLinkedListInsertPrime(int key)
{
  int index = 0;
  bool dupe = false;
  index = hashFunctionPrime(key);

  if (table[index] == NULL)
  {
    table[index] = createNode(key, NULL);
    table[index]->head = createNodeLL(key, NULL);
    // cout << "Inserted1";
    // return table[index];
  }
  else if (table[index] != NULL)
  {
    linkedListNode *ll = createNodeLL(key, NULL);
    if (table[index]->head == NULL)
    {
      table[index]->head = ll;
      // cout << "Inserted2";
      // return table[index];
    }
    else
    {
      linkedListNode *temp = table[index]->head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = ll;
      // cout << "Inserted3";
      // return table[index];
    }
  }
  return table[index];
}

int HashTable::chainingLinkedListSearch(int key)
{
  int count = 0;
  int index = hashFunction(key);

  if (table[index] == NULL)
  {
    return -1;
  }
  else
  {
    if (table[index]->key == key)
    {
      // cout << "Found at head." << endl;
      return count;
    }
    else
    {
      linkedListNode *temp = table[index]->head;
      while (temp != NULL)
      {
        if (temp->key == key)
        {
          count++;
          return count;
        }
        else
        {
          temp = temp->next;
          count++;
          // cout << count << endl;
        }
      }
    }
  }
  return -1;
}

int HashTable::chainingLinkedListSearchPrime(int key)
{
  int count = 0;
  bool found = false;
  int index = hashFunctionPrime(key);
  if (table[index] == NULL)
  {
    // cout << "Null linked list. No head!" << endl;
    return -1;
  }
  else
  {
    if (table[index]->head->key == key)
    {
      found = true;
      // cout << "Found at head." << endl;
      return count;
    }
    else
    {
      linkedListNode *temp = table[index]->head;
      while (temp->next != NULL)
      {
        if (temp->next->key == key)
        {
          found = true;
          // cout << "Found in Linked List" << endl;
          count++;
          return count;
        }
        else
        {
          temp = temp->next;
          count++;
        }
      }
      // cout << "Not found in Linked List" << endl;
    }
  }
  return -1;
}

bool HashTable::chainingLinkedListDelete(int key)
{
  int index = hashFunction(key);
  int ind2 = chainingLinkedListSearch(key);
  if (ind2 == -1)
  {
    cout << "Key not found, could not Delete" << endl;
    return false;
  }
  else if (ind2 == 0)
  {
    linkedListNode *temp = table[index]->head;
    table[index]->head = table[index]->head->next;
    delete temp;
    return true;
  }
  else
  {
    linkedListNode *curr = table[index]->head;
    while (curr->next != NULL)
    {
      if (curr->next->key == key)
      {
        linkedListNode *temp2 = curr->next;
        curr->next = temp2->next;
        delete temp2;
        return true;
        break;
      }
      curr = curr->next;
    }
  }
  return false;
}

bool HashTable::chainingLinkedListDeletePrime(int key)
{
  int index = hashFunctionPrime(key);
  int ind2 = chainingLinkedListSearchPrime(key);
  if (ind2 == -1)
  {
    cout << "Key not found, could not Delete" << endl;
    return false;
  }
  else if (ind2 == 0)
  {
    linkedListNode *temp = table[index]->head;
    table[index]->head = table[index]->head->next;
    delete temp;
    return true;
  }
  else
  {
    linkedListNode *curr = table[index]->head;
    while (curr->next != NULL)
    {
      if (curr->next->key == key)
      {
        linkedListNode *temp2 = curr->next;
        curr->next = temp2->next;
        delete temp2;
        return true;
        break;
      }
      curr = curr->next;
    }
  }
  return false;
}

void printTreeBSTHelper(BST *node)
{
  if (node)
  {
    printTreeBSTHelper(node->leftChild);

    cout << node->key << " -> ";

    printTreeBSTHelper(node->rightChild);
  }
}

void HashTable::printTreeBST()
{
  for (int i = 0; i < 100; i++)
  {
    cout << i << "|| ";
    if (table[i] == NULL || table[i]->root == NULL)
    {
      cout << "NULL";
    }
    else
    {
      printTreeBSTHelper(table[i]->root);
    }
    cout << endl;
  }
}

BST *chainingBSTInsertHelper(int key, BST *curr)
{
  if (curr)
  {
    if (curr->key < key)
    {
      curr->rightChild = chainingBSTInsertHelper(key, curr->rightChild);
    }
    else if (curr->key > key)
    {
      curr->leftChild = chainingBSTInsertHelper(key, curr->leftChild);
    }
    // return curr;
  }
  else
  {
    curr = new BST;
    curr->key = key;
    curr->leftChild = NULL;
    curr->rightChild = NULL;
    // cout << "Inserted into Tree" << endl;

    // curr = nn;
  }
  return curr;
}

node *HashTable::chainingBSTInsert(int key)
{
  int index = hashFunction(key);
  // cout << index << endl;
  if (table[index] == NULL)
  {
    table[index] = createNode(key, NULL);
    table[index]->root = createNodeBST(key, NULL, NULL);
    // cout << "Inserted into NULL" <<endl;
  }
  else if (table[index] != NULL)
  {
    table[index]->root = chainingBSTInsertHelper(key, table[index]->root);
  }

  return table[index];
}

node *HashTable::chainingBSTInsertPrime(int key)
{
  int index = hashFunctionPrime(key);
  // cout << index << endl;
  if (table[index] == NULL)
  {
    table[index] = createNode(key, NULL);
    table[index]->root = createNodeBST(key, NULL, NULL);
    // cout << "Inserted into NULL" <<endl;
  }
  else if (table[index] != NULL)
  {
    table[index]->root = chainingBSTInsertHelper(key, table[index]->root);
  }

  return table[index];
}

bool chainingBSTSearchHelper(BST *node, int key)
{
  bool found = false;
  if (node == NULL)
  {
    //  cout << "Not Found, Empty Tree" << endl;
    return found;
  }
  else if (node->key != key)
  {
    if (node->key > key)
    {
      chainingBSTSearchHelper(node->leftChild, key);
    }
    else if (node->key < key)
    {
      chainingBSTSearchHelper(node->rightChild, key);
    }
  }
  else if (node->key == key)
  {
    // cout << "Found in Tree" << endl;
    found = true;
    return found;
  }

  return found;
}

bool HashTable::chainingBSTSearch(int key)
{
  bool found = false;
  int index = hashFunction(key);
  if (table[index] != NULL)
  {
    found = chainingBSTSearchHelper(table[index]->root, key);
  }
  return found;
}

bool HashTable::chainingBSTSearchPrime(int key)
{
  bool found = false;
  int index = hashFunctionPrime(key);
  if (table[index] != NULL)
  {
    found = chainingBSTSearchHelper(table[index]->root, key);
  }
  return found;
}

BST *minNode(BST *node)
{
  if (node->leftChild == NULL)
  {
    return node;
  }
  return minNode(node->leftChild);
}

BST *chainingBSTDeleteHelper(BST *node, int key)
{
  if (node)
  {
    if (node->key < key)
    {
      node->rightChild = chainingBSTDeleteHelper(node->rightChild, key);
    }
    else if (node->key > key)
    {
      node->leftChild = chainingBSTDeleteHelper(node->leftChild, key);
    }
    else
    {
      if (node->leftChild == NULL && node->rightChild == NULL)
      {
        delete node;
        node = NULL;
        //  cout << "Deleted with no children" << endl;
      }
      else if (node->leftChild != NULL && node->rightChild == NULL)
      {
        BST *delNode = node;
        node = node->leftChild;
        delete delNode;
        //  cout << "Deleted with leftChild as replacement" << endl;
      }
      else if (node->leftChild == NULL && node->rightChild != NULL)
      {
        BST *delNode = node;
        node = node->rightChild;
        delete delNode;
        //  cout << "Deleted with rightChild as replacement" << endl;
      }
      else
      {
        BST *minN = minNode(node->rightChild);
        node->key = minN->key;
        delete minN;
        minN = NULL;
        node->rightChild = chainingBSTDeleteHelper(node->rightChild, key);
        //  cout << "Delete with minNode replacement" << endl;
      }
    }
  }
  return node;
}

bool HashTable::chainingBSTDelete(int key)
{
  bool del = false;
  int index = hashFunction(key);
  if (table[index] == NULL || table[index]->root == NULL)
  {
    //  cout << "Unable to Delete as the Tree is NULL" << endl;
  }
  else
  {
    table[index]->root = chainingBSTDeleteHelper(table[index]->root, key);
    del = true;
  }
  return del;
}

bool HashTable::chainingBSTDeletePrime(int key)
{
  bool del = false;
  int index = hashFunctionPrime(key);
  if (table[index] == NULL || table[index]->root == NULL)
  {
    //  cout << "Unable to Delete as the Tree is NULL" << endl;
  }
  else
  {
    table[index]->root = chainingBSTDeleteHelper(table[index]->root, key);
    del = true;
  }
  return del;
}

void HashTable::printProbeTable()
{
  for (int i = 0; i < 100; i++)
  {
    cout << i << "|| ";
    if (table[i] == NULL)
    {
      cout << "NULL" << endl;
    }
    else
    {
      cout << table[i]->key << endl;
    }
  }
}

int HashTable::linearProbeInsert(int key)
{
  bool adds = false;
  int index = hashFunction(key);

  for (int i = index; i < tableSize; i++)
  {
    if (table[i] != NULL)
    {
      if (table[i]->key == key)
      {
        // cout << "duplicate key, cannot insert" << endl;
        adds = true;
        return -1;
        break;
      }
    }
    else
    {
      table[i] = createNode(key, table[i + 1]);
      adds = true;
      return 1;
      break;
    }
  }
  if (adds == false)
  {
    for (int j = 0; j < index; j++)
    {
      if (table[j] != NULL)
      {
        if (table[j]->key == key)
        {
          //  cout << "duplicate key, cannot insert" << endl;
          return -1;
          break;
        }
      }
      else
      {
        table[j] = createNode(key, table[j + 1]);
        adds = true;
        return 1;
        break;
      }
    }
    if (adds == false)
    {
      cout << "Could not add, Table is full" << endl;
    }
  }
  return 0;
}

int HashTable::linearProbeInsertPrime(int key)
{
  bool adds = false;
  int index = hashFunctionPrime(key);

  for (int i = index; i < tableSize; i++)
  {
    if (table[i] != NULL)
    {
      if (table[i]->key == key)
      {
        // cout << "duplicate key, cannot insert" << endl;
        adds = true;
        return -1;
        break;
      }
    }
    else
    {
      table[i] = createNode(key, table[i + 1]);
      adds = true;
      return 1;
      break;
    }
  }
  if (adds == false)
  {
    for (int j = 0; j < index; j++)
    {
      if (table[j] != NULL)
      {
        if (table[j]->key == key)
        {
          //  cout << "duplicate key, cannot insert" << endl;
          return -1;
          break;
        }
      }
      else
      {
        table[j] = createNode(key, table[j + 1]);
        adds = true;
        return 1;
        break;
      }
    }
    if (adds == false)
    {
      cout << "Could not add, Table is full" << endl;
    }
  }
  return 0;
}

int HashTable::linearProbeSearch(int key)
{
  int index = hashFunction(key);
  bool found = false;
  for (int i = index; i < tableSize; i++)
  {
    if (table[i] == NULL)
    {
      return -1;
    }
    else
    {
      if (table[i]->key == key)
      {
        found = true;
        return i;
      }
    }
  }
  if (found == false)
  {
    for (int j = 0; j < index; j++)
    {
      if (table[j] == NULL)
      {
        return -1;
      }
      else
      {
        if (table[j]->key == key)
        {
          found = true;
          return j;
        }
      }
    }
  }
  return -1;
}

int HashTable::linearProbeSearchPrime(int key)
{
  int index = hashFunctionPrime(key);
  bool found = false;
  for (int i = index; i < tableSize; i++)
  {
    if (table[i] == NULL)
    {
      return -1;
    }
    else
    {
      if (table[i]->key == key)
      {
        found = true;
        return i;
      }
    }
  }
  if (found == false)
  {
    for (int j = 0; j < index; j++)
    {
      if (table[j] == NULL)
      {
        return -1;
      }
      else
      {
        if (table[j]->key == key)
        {
          found = true;
          return j;
        }
      }
    }
  }
  return -1;
}

bool HashTable::linearProbeDelete(int key)
{
  int index = hashFunction(key);
  bool deld = false;
  int ind2 = linearProbeSearch(key);
  if (ind2 != -1)
  {
    table[ind2] = NULL;
    deld = true;
  }
  else
  {
    cout << "Key not found, could not delete" << endl;
  }
  return deld;
}

bool HashTable::linearProbeDeletePrime(int key)
{
  int index = hashFunctionPrime(key);
  bool deld = false;
  int ind2 = linearProbeSearchPrime(key);
  if (ind2 != -1)
  {
    table[ind2] = NULL;
    deld = true;
  }
  else
  {
    cout << "Key not found, could not delete" << endl;
  }
  return deld;
}

void HashTable::printCuckooTables()
{
  for (int i = 0; i < 100; i++)
  {
    cout << i << "|| ";
    if (table[i] == NULL && table2[i] == NULL)
    {
      cout << "NULL -- " << " NULL" << endl;
    }
    else if (table[i] == NULL && table2[i] != NULL)
    {
      cout << "NULL -- " << table2[i]->key << endl;
    }
    else if (table[i] != NULL && table2[i] == NULL)
    {
      cout << table[i]->key << " -- NULL" << endl;
    }
    else
    {
      cout << table[i]->key << " -- " << table2[i]->key << endl;
    }
  }
}

int HashTable::cuckooHashingSearch(int key)
{
  int index1 = hashFunction(key);
  int index2 = hashFunctionPrime(key);
  int found = 0;

  if (table[index1] != NULL)
  {
    if (table[index1]->key == key)
    {
      found = 1;
      // cout << "Key found in first table" << endl;
      return found;
    }
    else
    {
      if (table2[index2] != NULL)
      {
        if (table2[index2]->key == key)
        {
          found = 2;
          // cout << "Key found in second table" << endl;
          return found;
        }
        else
        {
          // cout << "Key not found in either table" << endl;
        }
      }
      else
      {
        // cout << "Key not found " << endl;
      }
    }
  }
  else
  {
    if (table2[index2] != NULL)
    {
      if (table2[index2]->key == key)
      {
        //  cout << "Found in second table, first empty" << endl;
        found = 2;
        return found;
      }
      else
      {
        // cout << "Not found in second table, first empty" << endl;
      }
    }
    else
    {
      // cout << "Both table empty at this index" << endl;
    }
  }
  return found;
}

bool HashTable::cuckooHashingDelete(int key)
{
  int index1 = hashFunction(key);
  int index2 = hashFunctionPrime(key);
  bool deld = false;

  int exists = cuckooHashingSearch(key);
  if (exists == 0)
  {
    cout << "Key not found, could not delete" << endl;
  }
  else if (exists == 1)
  {
    table[index1]->key = -1;
    deld = true;
  }
  else if (exists == 2)
  {
    table2[index2]->key = -1;
    deld = true;
  }

  return deld;
}

int HashTable::cuckooHashingInsert(int key)
{
  int miniCount = 0;
  int count = 0;
  int index1 = hashFunction(key);
  int index2 = hashFunctionPrime(key);
  int temp = -1;
  int tab = -1;

  // cout << index1 << "    " << index2 << endl;

  while (table[index1] != NULL && table2[index2] != NULL)
  {
    if (miniCount == tableSize)
    {
      cout << "Both tables full... Resizing" << endl;
      count++;
      tableSize++;
    }
    miniCount++;
    index1 = hashFunction(key);
    index2 = hashFunctionPrime(key);
    if (tab == -1)
    {
      temp = table[index1]->key;
      table[index1]->key = key;
      key = temp;
      tab = 1;
      break;
    }
    else if (tab == 1)
    {
      temp = table2[index2]->key;
      table2[index2]->key = key;
      key = temp;
      tab = 2;
      break;
    }
    else if (tab == 2)
    {
      temp = table[index1]->key;
      table[index1]->key = key;
      key = temp;
      tab = 1;
    }
  }
  if (table[index1] == NULL)
  {
    table[index1] = createNode(key, table[index1 + 1]);
    // cout << "Inserted into first table" << endl;
  }
  else if (table2[index2] == NULL)
  {
    table2[index2] = createNode(key, table[index2 + 1]);
    // cout << "Inserted into second table" << endl;
  }
  return count;
}
