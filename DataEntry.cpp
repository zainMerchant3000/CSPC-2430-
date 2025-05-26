#include "DataEntry.h"
#include <vector>
#include <iostream>
//#include "CovidDB.h"
//#include "SeperateChaining.h"



string DataEntry::getCountry() {
	return country;

}//getCountry getter function

string DataEntry::getDate() {
	return date;

}//getDate getter function

int DataEntry::getDeaths() {
	return c_deaths;

}//getCountry getter function

int DataEntry::getCases() {
	return c_cases;

}//getCountry getter function

void DataEntry::setCases(int c_cases) {
	this->c_cases = c_cases;
}//setCases

void DataEntry::setDeaths(int c_deaths) {
	this->c_deaths = c_deaths;
}//setCases

void DataEntry::setDate(string date) {
	this->date = date;
}//setCases







