#include <algorithm>
#include "CovidDB.h"
#include "DataEntry.h"
#include "SeperateChaining.h"
#include "string"
#include <iostream>
using namespace std;

int CovidDB::getIndex(string country) {
	int sum = 0;//create sum variable
	for (int i = 1; i <= country.size(); i++) {//looping through every character in the string
		sum += (i * country[i - 1]);//hash function multiply position of character
		//(represented by i) by ascii value of character in that position represented by
		//country[i-1]
		sum %= v.size();//do sum % hashTable size(17) to complete hash function
	}//for
	return sum;//return index resulted in hash function
}//hash function for country

CovidDB::~CovidDB() {//destructor
	clearVector();//call function to clearVector in order to create new initial table
}//destructor

void CovidDB::add(DataEntry d, bool doneReadingFile) {
	
	auto& w = v[getIndex(d.getCountry())];//w stores the address of the passed country
	auto it = find_if(w.begin(), w.end(), [&d](auto& e) {
		return e.getCountry() == d.getCountry(); });
	//create variable to store find_if function
	//find_if function -> w.begin(), w.end() iterate through every country at that specfic index
	// iterating through inner vector (checking to see when there is a different country entry)
	//find_if function will iterate through each country's data Entrys until it reaches end
	if (it == w.end()) {
		// not found (implies country name does not match)
		//add this most recent entry
		w.push_back(d);//push DataEntry back
	}//if
	else {
		// found update entry (country name is the same -> keep adding/cumulate sum
		//of Covid Deaths and cases and get most current date
		
		string csvEndDate = "10/14/2021";
		string csvBeginningDate = "1/3/2020";
		//if date is less than or equal to most current date in initial hash table
		//(10/14/21) and the 
		if (d.getDate() <= csvEndDate && doneReadingFile) {
			//don't add entry
		}//if
		else {//otherwise date entry is greater than initial hash table date
			//&& file has been completley read
			//keep adding accumulating (becomes most recent entry)
			it->setDeaths(it->getDeaths() + d.getDeaths());
			it->setCases(it->getCases() + d.getCases());
			it->setDate(d.getDate());
			
		}//else
	}//else
}//add

DataEntry* CovidDB::get(string country) {
	auto& w = v[getIndex(country)];//variable w stores appropiate address of index of passed country
	//(uses hash function to determine where country should be placed in Hash table
	for (int i = 0; i < w.size(); i++) {
		if (w[i].getCountry() == country) {//if country is located/found
			return &w[i];//return address of passed country
		}//if
	}//for
	return nullptr;//country does not exist in Hash Table (never enters if statement)
}//get

void CovidDB::remove(string country) {
	// get index first
	int i = getIndex(country);
	// traverse ith list(vector) to search 
	for (int j = 0; j < v[i].size(); j++) {
		// if found, delete
		if (v[i][j].getCountry() == country) {
			v[i].erase(v[i].begin() + j);

			return;
		}//if
	}//for

}//remove

void CovidDB::display() {
	for (int i = 0; i < v.size(); i++) {//outer for loop 
		cout << i;//display indexes of Hash Table
		for (int j = 0; j < v[i].size(); j++) {//inner for loop display each country in
			//specific index
			cout << " -> " << v[i][j].getCountry();//showing collisions of countries using
			//seperate chaining
			cout << endl;
		}//for
	}//for
}//display

void CovidDB::clearVector() {//function to delete 2D Vector
	v.clear();//destory/empty 2D vector
}//clearVector

void CovidDB::reSize(int n) {//function to reSize vector once it has been
	//destroyed/emptied
	v.resize(n);//resize function re-defines size of Vector
}//reSize






