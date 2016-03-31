#include <iostream>
#include <string>
#include <cassert>
#include "Venue.h"
#include "Seat_Row.h"
#include "Seat.h"
#include "Address.h"

using namespace std;

Venue* addVenue();

int main() {
	int funcsel = 0;
	int venue_count = 0;
	Venue* venue_[100];

	cout << "Logged in as System Administrator" << endl;

	while (true) {
		cout << "To add a venue enter \"1\". To exit, enter -1." << endl;
		cin >> funcsel;

		cin.ignore(INT_MAX, '\n');

		switch (funcsel) {
		case 1:
			venue_[venue_count] = addVenue();
			venue_count++;
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

	cout << "\nEnter the name of the venue: ";
	cin >> name;
	cout << "\nStreet Address: ";
	cin >> street;
	cout << "\nCity: ";
	cin >> city;
	cout << "\nState: ";
	cin >> state;
	cout << "\nZip: ";
	cin >> zip;
	cout << endl;

	Address address_ = Address(street, city, state, zip);

	Venue* venue_ = new Venue(name, address_);

	return venue_;
}
