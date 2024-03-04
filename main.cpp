/*
Elizabeth Marticello
Mod 5 Assignment 
02-04-2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void ReadFile(vector<string>& cityNamesList, vector<double>& cityTempsList) {
	ifstream inFS;
	string fileCity;
	int fileTemp;

	cout << "Opening FahrenheitTemperature.txt ..." << endl;
	inFS.open("FahrenheitTemperature.txt");

	if (!inFS.is_open()) {
		cout << "Could not open FahrenheitTemperature.txt ..." << endl;
	}

	cout << "Reading data..." << endl;
	// Add to list
	while (!inFS.eof() && inFS.good()) {
		inFS >> fileCity >> fileTemp;
		cityNamesList.push_back(fileCity);
		cityTempsList.push_back(fileTemp);
	}

	cout << "Closing FahrenheitTemperature.txt ..." << endl;
	inFS.close();
}

void TempConvert(vector<double>& cityTempsList) {
	double convertedTemp;

	cout << "Converting now..." << endl;
	for (int i = 0; i < cityTempsList.size(); ++i) {
		convertedTemp = (cityTempsList.at(i) - 32) * (5.0 / 9.0);
		cityTempsList.at(i) = convertedTemp;
	}
}

void WriteFile(vector<string>& cityNamesList, vector<double>& cityTempsList) {
	ofstream outFS;

	cout << "Opening CelsiusTemperature.txt now..." << endl;
	outFS.open("CelsiusTemperature.txt");

	if (!outFS.is_open()) {
		cout << "Could not open CelsiusTemperature.txt ..." << endl;
	}

	cout << "Writing now..." << endl;
	for (int i = 0; i < cityNamesList.size(); ++i) {
		outFS << cityNamesList.at(i) << " " << cityTempsList.at(i) << endl;
	}

	cout << "Closing CelsiusTemperature.txt ..." << endl;
	outFS.close();
}

int main() {
	vector<string> cityNamesList;
	vector<double> cityTempsList;

	ReadFile(cityNamesList, cityTempsList);
	TempConvert(cityTempsList);
	WriteFile(cityNamesList, cityTempsList);

	cout << "Ending Program." << endl;
	return 0;
}
