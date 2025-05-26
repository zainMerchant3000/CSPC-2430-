#ifndef _SEPERATECHAINING_H
#define _SEPERATECHAINING_H
#include <iostream>
#include <vector>
//#include <string>
using namespace std;

class SeperateChaining
{
private:
    int tableSize;//variable to create size of hash table
    vector<vector<int>> v;//create nested vector for seperate chaining
public:
    // constructor
    SeperateChaining(int m) {//constructor for SeperateChaining (passing table size as argument?)
        v = vector<vector<int>>(m);//
        this->tableSize = m;
    }//constructor
    // hash function
    int getIndex(int key) {
        return key % tableSize;//retrieves index of stored key by returning/using hash function:
        //key % tableSize -> ex: 1989 % 10
    }
    // add a key to hash table
    void add(int key) {
        v[getIndex(key)].push_back(key);//v[getIndex(key)]
        //getIndex -> uses hash function to get proper index
        //[getIndex(key)] -> places key value in appropiate index in hash table
        //.push_back(key) -> places key at end of vector
    }
    // delete a key from hash table
    void deleteKey(int key) {
        // get index first
        int i = getIndex(key);
        // traverse ith list(vector) to search 
        for (int j = 0; j < v[i].size(); j++) {//traverse through inner vector (vector at specific index)
            // if found, delete
            if (v[i][j] == key) {//check whether value matches key
                v[i].erase(v[i].begin() + j);//v[i].erase(v[i].begin() + j);
                // v[i] -> the value of the element you want to erase
                //.erase(v[i].begin() + j);//deleting jth index value
                cout << key << " key: " << key << " is deleted!" << endl;
                return;
            }
        }
        cout << "No key: " << key << " in hash table!";
    }

    // Display the contents
    void display() {
        cout << "Hash Table" << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << i;
            for (int j = 0; j < v[i].size(); j++)
                cout << " -> " << v[i][j];
            cout << endl;
        }//for
    }//for
};//SeperateChaining
#endif





