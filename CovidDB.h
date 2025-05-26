#ifndef _COVIDDB_H
#define _COVIDDB_H
#include <string>
#include <iostream>
#include "DataEntry.h"
#include "SeperateChaining.h"

using namespace std;
class CovidDB
{

private:
	vector<vector<DataEntry>> v;//nested 2D vector 
	int getIndex(string country);//hash function for placing countries
public:
	
	CovidDB(int m) {
		v = vector<vector<DataEntry>>(m);//create 2D vector with (inner vector is vector
		//of DataEntrys
	}//constructor

	~CovidDB();//destructor
	void clearVector();//function to destroy vector
	//add() function should insert one data entry into the hash table. 
	void add(DataEntry entry, bool);

	// get() retrieves a data entry with the specific country name(string country). It returns NULL if 
	//no such entry exists
	DataEntry* get(string country);

	void display();//member function to display current state of hash table

	void remove(string country);
	//This function removes the data entry with the specific country name(string country).

	void reSize(int n);//function to reSize vector once it has been emptied

};//CovidDB
#endif
