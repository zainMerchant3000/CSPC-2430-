#ifndef _DATAENTRY_H
#define _DATAENTRY_H
#include <string>
//#include <iostream>

//#include <vector>
//#include "SeperateChaining.h"
//#include "CovidDB.h"
using namespace std;

class DataEntry
{
private:
    string date;
    int c_cases;
    int c_deaths;
    string country;

public:


    //constructor for DataEntry
    DataEntry(string date, string country, int cases, int deaths) {
        this->date = date;
        this->country = country;
        this->c_cases = cases;
        this->c_deaths = deaths;
    }//Constructor
    //getter functions
    string getCountry();
    string getDate();
    int getCases();
    int getDeaths();
    void setDeaths(int c_deaths);
    void setCases(int);
    void setDate(string date);
};//DataEntry

#endif