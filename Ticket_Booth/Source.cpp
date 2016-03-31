#include <iostream>
#include <string>
#include "Venue.h"
#include "Seat_Row.h"
#include "Seat.h"
#include "Address.h"

using namespace std;

Venue* addVenue();

int main() {
	int funcsel = 0;
	Venue* venue_;

	cout << "Logged in as System Administrator" << endl;

	while (true) {
		cout << "To add a venue enter \"1\". To exit, enter -1." << endl;
		cin >> funcsel;

		switch (funcsel) {
		case 1:
			venue_ = addVenue();
			break;
		case -1:
			return 0;
			break;
		default:
			cout << "Invalid input. Please try again." << endl;
		}
	}
}

Venue* addVenue() {
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
	cout << "\nZip" << endl;
	cin >> zip;

	Address address_ = Address(street, city, state, zip);

	Venue* venue_ = new Venue(name, address_);

	return venue_;
}