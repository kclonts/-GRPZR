#include <iostream>
#include <string>
#include "Address.h"

using namespace std;

Venue addVenue();

int main() {
	//int funcsel;
	Venue venues[1];

	cout << "Logged in as System Administrator" << endl;
	//cout << "What would you like to do?\nenter 1 for adding a venue" << endl;

	//cin >> funcsel;

	venues[0] = addVenue();


}

Venue addVenue() {
	string name, street, city, state;
	int zip;

	cout << "\nEnter the name of the venue" << endl;
	cin >> name;
	cout << "\nStreet Address" << endl;
	cin >> street;
	cout << "\nCity" << endl;
	cin >> city;
	cout << "\nState" << endl;
	cin >> state;
	cout << "\nZip";
	cin >> zip;

	Address* address_ = new Address(street, city, state, zip);

	Venue* venue_ = new Venue(name, address);

	return venue;
}