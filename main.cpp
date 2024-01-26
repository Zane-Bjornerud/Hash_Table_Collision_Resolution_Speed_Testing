#include "hashTable.hpp"
#include "hashTable.cpp"
#include <fstream>
#include <sstream>
#include <string>
#include <ctime> //timer
#include <stdlib.h> //random number
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

//key:
// - //////// -> change in load factor
// - ******** -> change in hash function ie. regular to floor
// - ######## -> change in chaining resolution ie. linkedList to BST


int main(int argc, char *argv[]){


  int tablesizeUsable = 10009;

  HashTable hashObj(10009);

  string line;
  string numString;
  int numInt;

  srand (time(NULL));
  int randNum;
  float countLoadFactor = 0;
  int count100;

  int startTime1, endTime1;
  double execTime1;
  double execTimeTotal1 = 0;

  int startTime2, endTime2;
  double execTime2;
  double execTimeTotal2 = 0;

  int startTime3, endTime3;
  double execTime3;
  double execTimeTotal3 = 0;

  ifstream fs;
  vector<int> randVec;
  string vecString;
  int vecInt;
  fs.open(argv[1]);

  while(!fs.eof()){
    getline(fs, vecString, ',');
    vecInt = stoi(vecString);
    randVec.push_back(vecInt);
  }
  fs.close();
  fs.open(argv[1]);

 //LinkedList Test Cases
  hashObj.chainingLinkedListInsert(0);
  hashObj.chainingLinkedListInsert(10009);
  hashObj.printTableLL();
  hashObj.chainingLinkedListInsert(20018);
  hashObj.printTableLL();
  hashObj.chainingLinkedListInsert(0);
  hashObj.printTableLL();
  cout << hashObj.chainingLinkedListSearch(20018) << endl;
  hashObj.chainingLinkedListDelete(20018);
  hashObj.printTableLL();
  

/* //BST Test cases
  hashObj.chainingBSTInsert(2);
  hashObj.chainingBSTInsert(4);
  hashObj.chainingBSTInsert(10011);
  hashObj.printTreeBST();
  hashObj.chainingBSTDelete(4);
  hashObj.printTreeBST();
  hashObj.chainingBSTDelete(2);
  hashObj.printTreeBST();
  */
  /*
  //Linear Probe Test cases
  cout << "hi" << endl;
  hashObj.linearProbeInsert(6);
  cout << "Insert" << endl;
  hashObj.linearProbeInsert(8);
  cout << "Print" << endl;
  hashObj.printProbeTable();

  hashObj.linearProbeInsert(6);
  hashObj.printProbeTable();
  cout << "-----------" << endl;
  hashObj.linearProbeInsert(10015);
  hashObj.printProbeTable();
  cout << "search" << endl;
  hashObj.linearProbeSearch(8);
  cout << "delete" << endl;
  hashObj.linearProbeDelete(6);
  hashObj.printProbeTable();
  */

  //Cuckoo Test cases
  /*
  hashObj.cuckooHashingInsert(2);
  hashObj.cuckooHashingInsert(4);
  hashObj.cuckooHashingInsert(6);
  cout << "print" << endl;
  hashObj.printCuckooTables();
  cout << "insert2" << endl;
  hashObj.cuckooHashingInsert(10011);
  hashObj.printCuckooTables();
  hashObj.cuckooHashingSearch(4);
  hashObj.cuckooHashingDelete(2);
*/






  ///////////////////////////////////////////
  ///////////////////////////////////////////
  //Linked List
  //regular hash function
  //load factor of .1

  cout << "Inserting until first load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .1){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          //cout << numInt << endl;
          while(hashObj.chainingLinkedListSearch(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsert(numInt);
          countLoadFactor++;


        }
  }
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTableLL();

  count100 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;


  ////////////////////////////////////////////////
  ////////////////////////////////////////////////
/*
  //load factor of .2
  cout << "Inserting until second load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .2){

        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearch(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsert(numInt);
          countLoadFactor++;
        }
      //}
  }
  cout << endl;
  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////
  //////////////////////////////////////////////
/*
  //load factor of .5
  cout << "Inserting until third load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .5){
      // getline(fs, line);
      // if(line != ""){
      //   stringstream ss(line);
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearch(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsert(numInt);
          countLoadFactor++;
        }
      //}
  }
  cout << endl;
  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
  */

  ///////////////////////////////////////
  ///////////////////////////////////////
/*
  //load factor of .7
  cout << "Inserting until fourth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .7){
      // getline(fs, line);
      // if(line != ""){
      //   stringstream ss(line);
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearch(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsert(numInt);
          countLoadFactor++;
        }
      //}
  }
  cout << endl;
  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  ////////////////////////////////////////
  ////////////////////////////////////////
/*
  //load factor of .9
  cout << "Inserting until fifth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .9){
      // getline(fs, line);
      // if(line != ""){
      //   stringstream ss(line);
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearch(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsert(numInt);
          countLoadFactor++;
        }
      //}
  }
  cout << endl;
  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;

*/

  /////////////////////////////////////
  /////////////////////////////////////
/*
  //load factor of 1.0
  cout << "Inserting until last load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= 1.0){
      // getline(fs, line);
      // if(line != ""){
      //   stringstream ss(line);
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearch(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsert(numInt);
          countLoadFactor++;
        }
      //}
  }
  cout << endl;
  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;

*/



  //***************************************************************************************
  //***************************************************************************************
  //Floor hash function
/*
  cout << "--USING FLOOR HASH FUNCTION--" << endl;

  //load factor of .1
  cout << "Inserting until first load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .1){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          //cout << numInt << endl;
          while(hashObj.chainingLinkedListSearchPrime(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTableLL();

  count100 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;

*/
  ////////////////////////////////////////////////////
  ////////////////////////////////////////////////////
/*
  //load factor of .2
  cout << "Inserting until second load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .2){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearchPrime(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
/*
  //load factor of .5
  cout << "Inserting until third load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .5){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearchPrime(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;

*/
  ///////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////
/*
  //load factor of .7
  cout << "Inserting until fourth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .7){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearchPrime(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  ///////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////
/*
  //load factor of .9
  cout << "Inserting until fifth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .9){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearchPrime(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/


  /////////////////////////////////////////////
  /////////////////////////////////////////////
/*
  //load factor of 1.0
  cout << "Inserting until last load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= 1.0){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingLinkedListSearchPrime(numInt) != -1){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingLinkedListInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTableLL();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingLinkedListInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingLinkedListSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingLinkedListDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Linked List average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/




//##############################################################################
//##############################################################################


/*
  //Binary Search Tree
  cout << "--BINARY SEARCH TREE --" << endl;
  //Regular Hash function
  //load factor of .1
  cout << "Inserting until first load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .1){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearch(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsert(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/
//
  ////////////////////////////////////////////
  ////////////////////////////////////////////
/*
  //load factor of .2
  cout << "Inserting until second load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .2){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearch(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsert(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  ////////////////////////////////////////////
  ////////////////////////////////////////////
/*
  //load factor of .5
  cout << "Inserting until third load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .5){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearch(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsert(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  ////////////////////////////////////////////
  ////////////////////////////////////////////
/*
  //load factor of .7
  cout << "Inserting until fourth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .7){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearch(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsert(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  ////////////////////////////////////////////
  ////////////////////////////////////////////
/*
  //load factor of .9
  cout << "Inserting until fifth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .9){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearch(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsert(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;

*/
  ////////////////////////////////////////////
  ////////////////////////////////////////////
/*
  //load factor of 1.0
  cout << "Inserting until last load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= 1.0){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearch(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsert(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/


  //****************************************************
  //****************************************************

/*
  //Floor hash function
  cout << "--USING FLOOR HASH FUNCTION--" << endl;
  //load factor of .1
  cout << "Inserting until first load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .1){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearchPrime(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of .2
  cout << "Inserting until second load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .2){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearchPrime(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of .5
  cout << "Inserting until third load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .5){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearchPrime(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of .7
  cout << "Inserting until fourth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .7){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearchPrime(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of .9
  cout << "Inserting until fifth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .9){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearchPrime(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();


  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of 1.0
  cout << "Inserting until last load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= 1.0){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.chainingBSTSearchPrime(numInt) != false){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          hashObj.chainingBSTInsertPrime(numInt);
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printTreeBST();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];

    startTime1 = clock();
    hashObj.chainingBSTInsertPrime(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.chainingBSTSearchPrime(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.chainingBSTDeletePrime(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;

    //

    count100++;

  }

  cout << "BST average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

//################################################################
//################################################################

/*
//Linear Probe
//regular hash function
//load factor of .1
cout << "Inserting until first load factor..." << endl;
while(countLoadFactor/tablesizeUsable <= .1){
      getline(fs, numString, ',');
      if(numString != ""){
        numInt = stoi(numString);
        if(hashObj.linearProbeInsert(numInt) != -1){
          countLoadFactor++;
        }
      }
}
cout << endl;
//cout << "Past load factor" << endl;

hashObj.printProbeTable();

count100 = 0;
cout << "Testing times..." << endl;
while(count100 < 100){
  randNum = randVec[rand() % randVec.size()];
  while(hashObj.linearProbeInsert(randNum) == -1){ //prevents timing on a duplicate number
    randNum = randVec[rand() % randVec.size()];
  }


  startTime1 = clock();
  hashObj.linearProbeInsert(randNum);
  endTime1 = clock();
  execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
  execTimeTotal1 = execTimeTotal1 + execTime1;

  startTime2 = clock();
  hashObj.linearProbeSearch(randNum);
  endTime2 = clock();
  execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
  execTimeTotal2 = execTimeTotal2 + execTime2;

  startTime3 = clock();
  hashObj.linearProbeDelete(randNum);
  endTime3 = clock();
  execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
  execTimeTotal3 = execTimeTotal3 + execTime3;


  count100++;

}

  cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  /////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////
/*
  //load factor of .2
  cout << "Inserting until second load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .2){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          //cout << numInt << endl;
          if(hashObj.linearProbeInsert(numInt) != -1){
            countLoadFactor++;
          }
        }
  }
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printProbeTable();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];
    while(hashObj.linearProbeInsert(randNum) == -1){ //prevents timing on a duplicate number
      randNum = randVec[rand() % randVec.size()];
    }

    startTime1 = clock();
    hashObj.linearProbeInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.linearProbeSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.linearProbeDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

    cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
    cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
    cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
    cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
/*
    //load factor of .5
    cout << "Inserting until third load factor..." << endl;
    while(countLoadFactor/tablesizeUsable <= .5){
          getline(fs, numString, ',');
          if(numString != ""){
            numInt = stoi(numString);
            //cout << numInt << endl;
            if(hashObj.linearProbeInsert(numInt) != -1){
              countLoadFactor++;
            }
          }
    }
    cout << endl;
    //cout << "Past load factor" << endl;

    hashObj.printProbeTable();

    count100 = 0;
    execTimeTotal1 = 0;
    execTimeTotal2 = 0;
    execTimeTotal3 = 0;
    cout << "Testing times..." << endl;
    while(count100 < 100){
      randNum = randVec[rand() % randVec.size()];
      while(hashObj.linearProbeInsert(randNum) == -1){ //prevents timing on a duplicate number
        randNum = randVec[rand() % randVec.size()];
      }

      startTime1 = clock();
      hashObj.linearProbeInsert(randNum);
      endTime1 = clock();
      execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
      execTimeTotal1 = execTimeTotal1 + execTime1;

      startTime2 = clock();
      hashObj.linearProbeSearch(randNum);
      endTime2 = clock();
      execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
      execTimeTotal2 = execTimeTotal2 + execTime2;

      startTime3 = clock();
      hashObj.linearProbeDelete(randNum);
      endTime3 = clock();
      execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
      execTimeTotal3 = execTimeTotal3 + execTime3;


      count100++;

    }

      cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
      cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
      cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
      cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

      /////////////////////////////////////////////////////////
      /////////////////////////////////////////////////////////
/*
      //load factor of .7
      cout << "Inserting until fourth load factor..." << endl;
      while(countLoadFactor/tablesizeUsable <= .7){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
              //cout << numInt << endl;
              if(hashObj.linearProbeInsert(numInt) != -1){
                countLoadFactor++;
              }
            }
      }
      cout << endl;
      //cout << "Past load factor" << endl;

      hashObj.printProbeTable();

      count100 = 0;
      execTimeTotal1 = 0;
      execTimeTotal2 = 0;
      execTimeTotal3 = 0;
      cout << "Testing times..." << endl;
      while(count100 < 100){
        randNum = randVec[rand() % randVec.size()];
        while(hashObj.linearProbeInsert(randNum) == -1){ //prevents timing on a duplicate number
          randNum = randVec[rand() % randVec.size()];
        }

        startTime1 = clock();
        hashObj.linearProbeInsert(randNum);
        endTime1 = clock();
        execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
        execTimeTotal1 = execTimeTotal1 + execTime1;

        startTime2 = clock();
        hashObj.linearProbeSearch(randNum);
        endTime2 = clock();
        execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
        execTimeTotal2 = execTimeTotal2 + execTime2;

        startTime3 = clock();
        hashObj.linearProbeDelete(randNum);
        endTime3 = clock();
        execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
        execTimeTotal3 = execTimeTotal3 + execTime3;


        count100++;

      }

        cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
        cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
        cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
        cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
/*
        //load factor of .9
        cout << "Inserting until fifth load factor..." << endl;
        while(countLoadFactor/tablesizeUsable <= .9){
              getline(fs, numString, ',');
              if(numString != ""){
                numInt = stoi(numString);
                //cout << numInt << endl;
                if(hashObj.linearProbeInsert(numInt) != -1){
                  countLoadFactor++;
                }
              }
        }
        cout << endl;
        //cout << "Past load factor" << endl;

        hashObj.printProbeTable();

        count100 = 0;
        execTimeTotal1 = 0;
        execTimeTotal2 = 0;
        execTimeTotal3 = 0;
        cout << "Testing times..." << endl;
        while(count100 < 100){
          randNum = randVec[rand() % randVec.size()];
          while(hashObj.linearProbeInsert(randNum) == -1){ //prevents timing on a duplicate number
            randNum = randVec[rand() % randVec.size()];
          }

          startTime1 = clock();
          hashObj.linearProbeInsert(randNum);
          endTime1 = clock();
          execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
          execTimeTotal1 = execTimeTotal1 + execTime1;

          startTime2 = clock();
          hashObj.linearProbeSearch(randNum);
          endTime2 = clock();
          execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
          execTimeTotal2 = execTimeTotal2 + execTime2;

          startTime3 = clock();
          hashObj.linearProbeDelete(randNum);
          endTime3 = clock();
          execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
          execTimeTotal3 = execTimeTotal3 + execTime3;


          count100++;

        }

          cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
          cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
          cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
          cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

          /////////////////////////////////////////////////////////
          /////////////////////////////////////////////////////////
/*
          //load factor of 1.0
          cout << "Inserting until last load factor..." << endl;
          while(countLoadFactor/tablesizeUsable <= 1.0){
                getline(fs, numString, ',');
                if(numString != ""){
                  numInt = stoi(numString);
                  //cout << numInt << endl;
                  if(hashObj.linearProbeInsert(numInt) != -1){
                    countLoadFactor++;
                  }
                }
          }
          cout << endl;
          //cout << "Past load factor" << endl;

          hashObj.printProbeTable();

          count100 = 0;
          execTimeTotal1 = 0;
          execTimeTotal2 = 0;
          execTimeTotal3 = 0;
          cout << "Testing times..." << endl;
          while(count100 < 100){
            randNum = randVec[rand() % randVec.size()];
            while(hashObj.linearProbeSearch(randNum) == -1){
              randNum = randVec[rand() % randVec.size()];
            }


            startTime2 = clock();
            hashObj.linearProbeSearch(randNum);
            endTime2 = clock();
            execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
            execTimeTotal2 = execTimeTotal2 + execTime2;

            startTime3 = clock();
            hashObj.linearProbeDelete(randNum);
            endTime3 = clock();
            execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
            execTimeTotal3 = execTimeTotal3 + execTime3;

            startTime1 = clock();
            hashObj.linearProbeInsert(randNum);
            endTime1 = clock();
            execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
            execTimeTotal1 = execTimeTotal1 + execTime1;


            count100++;

          }

            cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using regular hash function:" << endl;
            cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
            cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
            cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

//***********************************************************
//***********************************************************
/*
            //Linear Probe
            //floor hash function
            cout << "--Using Floor function" << endl;
            //load factor of .1
            cout << "Inserting until first load factor..." << endl;
            while(countLoadFactor/tablesizeUsable <= .1){
                  getline(fs, numString, ',');
                  if(numString != ""){
                    numInt = stoi(numString);
                    //cout << numInt << endl;
                    if(hashObj.linearProbeInsertPrime(numInt) != -1){
                      countLoadFactor++;
                    }
                  }
            }
            cout << endl;
            //cout << "Past load factor" << endl;

            hashObj.printProbeTable();

            count100 = 0;
            cout << "Testing times..." << endl;
            while(count100 < 100){
              randNum = randVec[rand() % randVec.size()];
              while(hashObj.linearProbeInsertPrime(randNum) == -1){ //prevents timing on a duplicate number
                randNum = randVec[rand() % randVec.size()];
              }

              startTime1 = clock();
              hashObj.linearProbeInsertPrime(randNum);
              endTime1 = clock();
              execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
              execTimeTotal1 = execTimeTotal1 + execTime1;

              startTime2 = clock();
              hashObj.linearProbeSearchPrime(randNum);
              endTime2 = clock();
              execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
              execTimeTotal2 = execTimeTotal2 + execTime2;

              startTime3 = clock();
              hashObj.linearProbeDeletePrime(randNum);
              endTime3 = clock();
              execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
              execTimeTotal3 = execTimeTotal3 + execTime3;


              count100++;

            }

              cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
              cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
              cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
              cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/
              /////////////////////////////////////////////////////////
              /////////////////////////////////////////////////////////
/*
              //load factor of .2
              cout << "Inserting until second load factor..." << endl;
              while(countLoadFactor/tablesizeUsable <= .2){
                    getline(fs, numString, ',');
                    if(numString != ""){
                      numInt = stoi(numString);
                      //cout << numInt << endl;
                      if(hashObj.linearProbeInsertPrime(numInt) != -1){
                        countLoadFactor++;
                      }
                    }
              }
              cout << endl;
              //cout << "Past load factor" << endl;

              hashObj.printProbeTable();

              count100 = 0;
              execTimeTotal1 = 0;
              execTimeTotal2 = 0;
              execTimeTotal3 = 0;
              cout << "Testing times..." << endl;
              while(count100 < 100){
                randNum = randVec[rand() % randVec.size()];
                while(hashObj.linearProbeInsertPrime(randNum) == -1){ //prevents timing on a duplicate number
                  randNum = randVec[rand() % randVec.size()];
                }

                startTime1 = clock();
                hashObj.linearProbeInsertPrime(randNum);
                endTime1 = clock();
                execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
                execTimeTotal1 = execTimeTotal1 + execTime1;

                startTime2 = clock();
                hashObj.linearProbeSearchPrime(randNum);
                endTime2 = clock();
                execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
                execTimeTotal2 = execTimeTotal2 + execTime2;

                startTime3 = clock();
                hashObj.linearProbeDeletePrime(randNum);
                endTime3 = clock();
                execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
                execTimeTotal3 = execTimeTotal3 + execTime3;


                count100++;

              }

                cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
                cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
                cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
                cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

                /////////////////////////////////////////////////////////
                /////////////////////////////////////////////////////////
/*
                //load factor of .5
                cout << "Inserting until third load factor..." << endl;
                while(countLoadFactor/tablesizeUsable <= .5){
                      getline(fs, numString, ',');
                      if(numString != ""){
                        numInt = stoi(numString);
                        //cout << numInt << endl;
                        if(hashObj.linearProbeInsertPrime(numInt) != -1){
                          countLoadFactor++;
                        }
                      }
                }
                cout << endl;
                //cout << "Past load factor" << endl;

                hashObj.printProbeTable();

                count100 = 0;
                execTimeTotal1 = 0;
                execTimeTotal2 = 0;
                execTimeTotal3 = 0;
                cout << "Testing times..." << endl;
                while(count100 < 100){
                  randNum = randVec[rand() % randVec.size()];
                  while(hashObj.linearProbeInsertPrime(randNum) == -1){ //prevents timing on a duplicate number
                    randNum = randVec[rand() % randVec.size()];
                  }

                  startTime1 = clock();
                  hashObj.linearProbeInsertPrime(randNum);
                  endTime1 = clock();
                  execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
                  execTimeTotal1 = execTimeTotal1 + execTime1;

                  startTime2 = clock();
                  hashObj.linearProbeSearchPrime(randNum);
                  endTime2 = clock();
                  execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
                  execTimeTotal2 = execTimeTotal2 + execTime2;

                  startTime3 = clock();
                  hashObj.linearProbeDeletePrime(randNum);
                  endTime3 = clock();
                  execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
                  execTimeTotal3 = execTimeTotal3 + execTime3;


                  count100++;

                }

                  cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
                  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
                  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
                  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

                  /////////////////////////////////////////////////////////
                  /////////////////////////////////////////////////////////
                  //load factor of .7
/*
                  cout << "Inserting until fourth load factor..." << endl;
                  while(countLoadFactor/tablesizeUsable <= .7){
                        getline(fs, numString, ',');
                        if(numString != ""){
                          numInt = stoi(numString);
                          //cout << numInt << endl;
                          if(hashObj.linearProbeInsertPrime(numInt) != -1){
                            countLoadFactor++;
                          }
                        }
                  }
                  cout << endl;
                  //cout << "Past load factor" << endl;

                  hashObj.printProbeTable();

                  count100 = 0;
                  execTimeTotal1 = 0;
                  execTimeTotal2 = 0;
                  execTimeTotal3 = 0;
                  cout << "Testing times..." << endl;
                  while(count100 < 100){
                    randNum = randVec[rand() % randVec.size()];
                    while(hashObj.linearProbeInsertPrime(randNum) == -1){ //prevents timing on a duplicate number
                      randNum = randVec[rand() % randVec.size()];
                    }

                    startTime1 = clock();
                    hashObj.linearProbeInsertPrime(randNum);
                    endTime1 = clock();
                    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
                    execTimeTotal1 = execTimeTotal1 + execTime1;

                    startTime2 = clock();
                    hashObj.linearProbeSearchPrime(randNum);
                    endTime2 = clock();
                    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
                    execTimeTotal2 = execTimeTotal2 + execTime2;

                    startTime3 = clock();
                    hashObj.linearProbeDeletePrime(randNum);
                    endTime3 = clock();
                    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
                    execTimeTotal3 = execTimeTotal3 + execTime3;


                    count100++;

                  }

                    cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
                    cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
                    cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
                    cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

                    /////////////////////////////////////////////////////////
                    /////////////////////////////////////////////////////////
/*
                    //load factor of .9
                    cout << "Inserting until fifth load factor..." << endl;
                    while(countLoadFactor/tablesizeUsable <= .9){
                          getline(fs, numString, ',');
                          if(numString != ""){
                            numInt = stoi(numString);
                            //cout << numInt << endl;
                            if(hashObj.linearProbeInsertPrime(numInt) != -1){
                              countLoadFactor++;
                            }
                          }
                    }
                    cout << endl;
                    //cout << "Past load factor" << endl;

                    hashObj.printProbeTable();

                    count100 = 0;
                    execTimeTotal1 = 0;
                    execTimeTotal2 = 0;
                    execTimeTotal3 = 0;
                    cout << "Testing times..." << endl;
                    while(count100 < 100){
                      randNum = randVec[rand() % randVec.size()];
                      while(hashObj.linearProbeInsertPrime(randNum) == -1){ //prevents timing on a duplicate number
                        randNum = randVec[rand() % randVec.size()];
                      }

                      startTime1 = clock();
                      hashObj.linearProbeInsertPrime(randNum);
                      endTime1 = clock();
                      execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
                      execTimeTotal1 = execTimeTotal1 + execTime1;

                      startTime2 = clock();
                      hashObj.linearProbeSearchPrime(randNum);
                      endTime2 = clock();
                      execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
                      execTimeTotal2 = execTimeTotal2 + execTime2;

                      startTime3 = clock();
                      hashObj.linearProbeDeletePrime(randNum);
                      endTime3 = clock();
                      execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
                      execTimeTotal3 = execTimeTotal3 + execTime3;


                      count100++;

                    }

                      cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
                      cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
                      cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
                      cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

                      /////////////////////////////////////////////////////////
                      /////////////////////////////////////////////////////////
/*
                      //load factor of 1.0
                      cout << "Inserting until last load factor..." << endl;
                      while(countLoadFactor/tablesizeUsable <= 1.0){
                            getline(fs, numString, ',');
                            if(numString != ""){
                              numInt = stoi(numString);
                              //cout << numInt << endl;
                              if(hashObj.linearProbeInsertPrime(numInt) != -1){
                                countLoadFactor++;
                              }
                            }
                      }
                      cout << endl;
                      //cout << "Past load factor" << endl;

                      hashObj.printProbeTable();

                      count100 = 0;
                      execTimeTotal1 = 0;
                      execTimeTotal2 = 0;
                      execTimeTotal3 = 0;
                      cout << "Testing times..." << endl;
                      while(count100 < 100){
                        randNum = randVec[rand() % randVec.size()];
                        while(hashObj.linearProbeSearchPrime(randNum) == -1){
                          randNum = randVec[rand() % randVec.size()];
                        }

                        startTime2 = clock();
                        hashObj.linearProbeSearchPrime(randNum);
                        endTime2 = clock();
                        execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
                        execTimeTotal2 = execTimeTotal2 + execTime2;

                        startTime3 = clock();
                        hashObj.linearProbeDeletePrime(randNum);
                        endTime3 = clock();
                        execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
                        execTimeTotal3 = execTimeTotal3 + execTime3;

                        startTime1 = clock();
                        hashObj.linearProbeInsertPrime(randNum);
                        endTime1 = clock();
                        execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
                        execTimeTotal1 = execTimeTotal1 + execTime1;




                        count100++;

                      }

                        cout << "Linear Probe average times with load factor of " << countLoadFactor/tablesizeUsable << " using floor hash function:" << endl;
                        cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
                        cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
                        cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;

*/

  //##########################################################
  //##########################################################
  //Cuckoo hashing
/*
  cout << "--Using Cuckoo Hashing--" << endl;
  //load factor of .1
  cout << "Inserting until first load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .1){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.cuckooHashingSearch(numInt) != 0){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          cout << hashObj.cuckooHashingInsert(numInt) << endl;
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printCuckooTables();

  count100 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];
    while(hashObj.cuckooHashingSearch(randNum) != 0){
      randNum = randVec[rand() % randVec.size()];
    }


    startTime1 = clock();
    hashObj.cuckooHashingInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.cuckooHashingSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.cuckooHashingDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Cuckoo average times with load factor of " << countLoadFactor/tablesizeUsable << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;

*/


  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of .2
  cout << "Inserting until second load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .2){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          //cout << numInt << endl;
          while(hashObj.cuckooHashingSearch(numInt) != 0){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          cout << hashObj.cuckooHashingInsert(numInt) << endl;
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printCuckooTables();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];
    while(hashObj.cuckooHashingSearch(randNum) != 0){
      randNum = randVec[rand() % randVec.size()];
    }

    startTime1 = clock();
    hashObj.cuckooHashingInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.cuckooHashingSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.cuckooHashingDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Cuckoo average times with load factor of " << countLoadFactor/tablesizeUsable << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of .5
  cout << "Inserting until third load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .5){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          //cout << numInt << endl;
          while(hashObj.cuckooHashingSearch(numInt) != 0){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          cout << hashObj.cuckooHashingInsert(numInt) << endl;
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printCuckooTables();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];
    while(hashObj.cuckooHashingSearch(randNum) != 0){
      randNum = randVec[rand() % randVec.size()];
    }

    startTime1 = clock();
    hashObj.cuckooHashingInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.cuckooHashingSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.cuckooHashingDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Cuckoo average times with load factor of " << countLoadFactor/tablesizeUsable << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of .7
  cout << "Inserting until fourth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .7){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          while(hashObj.cuckooHashingSearch(numInt) != 0){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          cout << hashObj.cuckooHashingInsert(numInt) << endl;
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printCuckooTables();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];
    while(hashObj.cuckooHashingSearch(randNum) != 0){
      randNum = randVec[rand() % randVec.size()];
    }

    startTime1 = clock();
    hashObj.cuckooHashingInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.cuckooHashingSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.cuckooHashingDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Cuckoo average times with load factor of " << countLoadFactor/tablesizeUsable << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
/*
  //load factor of .9
  cout << "Inserting until fifth load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= .9){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          //cout << numInt << endl;
          while(hashObj.cuckooHashingSearch(numInt) != 0){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          cout << hashObj.cuckooHashingInsert(numInt) << endl;
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printCuckooTables();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];
    while(hashObj.cuckooHashingSearch(randNum) != 0){
      randNum = randVec[rand() % randVec.size()];
    }

    startTime1 = clock();
    hashObj.cuckooHashingInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.cuckooHashingSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.cuckooHashingDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Cuckoo average times with load factor of " << countLoadFactor/tablesizeUsable << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/

/*
  //Test 1.0 and see how many times it needs to rehash
  cout << "Inserting until last load factor..." << endl;
  while(countLoadFactor/tablesizeUsable <= 1.0){
        getline(fs, numString, ',');
        if(numString != ""){
          numInt = stoi(numString);
          //cout << numInt << endl;
          while(hashObj.cuckooHashingSearch(numInt) != 0){
            getline(fs, numString, ',');
            if(numString != ""){
              numInt = stoi(numString);
            }
          }
          cout << hashObj.cuckooHashingInsert(numInt) << endl;
          countLoadFactor++;
        }
  }
  //cout << "Why" << endl;
  cout << endl;
  //cout << "Past load factor" << endl;

  hashObj.printCuckooTables();

  count100 = 0;
  execTimeTotal1 = 0;
  execTimeTotal2 = 0;
  execTimeTotal3 = 0;
  cout << "Testing times..." << endl;
  while(count100 < 100){
    randNum = randVec[rand() % randVec.size()];
    while(hashObj.cuckooHashingSearch(randNum) != 0){
      randNum = randVec[rand() % randVec.size()];
    }

    startTime1 = clock();
    hashObj.cuckooHashingInsert(randNum);
    endTime1 = clock();
    execTime1 = (double)(endTime1-startTime1)/CLOCKS_PER_SEC;
    execTimeTotal1 = execTimeTotal1 + execTime1;

    startTime2 = clock();
    hashObj.cuckooHashingSearch(randNum);
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    execTimeTotal2 = execTimeTotal2 + execTime2;

    startTime3 = clock();
    hashObj.cuckooHashingDelete(randNum);
    endTime3 = clock();
    execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
    execTimeTotal3 = execTimeTotal3 + execTime3;


    count100++;

  }

  cout << "Cuckoo average times with load factor of " << countLoadFactor/tablesizeUsable << endl;
  cout << "Insert: " << execTimeTotal1/100 << " seconds" << endl;
  cout << "Search: " << execTimeTotal2/100 << " seconds" << endl;
  cout << "Delete: " << execTimeTotal3/100 << " seconds" << endl;
*/
}
