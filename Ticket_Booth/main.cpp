#include <iostream>
#include <string>
#include <cassert>
#include "Venue.h"
#include "Seat_Row.h"
#include "Seat.h"
#include "Address.h"

using namespace std;

Venue* addVenue();
void inputseatrow(Venue* venue);
void AddSection();

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
			venue_[venue_count]->DisplayAll();
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

	inputseatrow(venue_);

	return venue_;
}

void inputseatrow(Venue* venue) {
	string space = " ";
	string row_name;
	int num_seats;
	int i = 0;
	int j = 0;

	Seat_Row* seat_row[100];
	Seat* seat;

	cout << "Enter seat row information\nEnter blank line for name when finished" << endl;

	do {

		cout << "\nRow Name: ";
		cin >> row_name;
		cout << "\nNumber of Seats: ";
		cin >> num_seats;

		seat_row[i] = new Seat_Row(row_name);

		while (j < num_seats) {
			seat = new Seat(++j);
			seat_row[i]->Add_Seat(seat);
		}

		venue->Add_Seat_Row(seat_row[0]);

		i++;

	} while (strcmp(row_name, space) != 0);
}
/*function to add new section*/
void Add_Section() {
	string str[MAX_ROWS];
	int row_begin[MAX_ROWS];
	int row_stop[MAX_ROWS];
	int ctr = 0;
	string name;

	cout << "Seating section name: " ;
	getline(cin, name);

	do {
			cout << "Row name: ";
			getline(cin, str[ctr]);
			if (str[ctr].empty()) {
				break;
			}
			else {
			cout << "First seat number: ";
			cin >> row_begin[ctr];
			cout << "Last row number: ";
			cin >> row_stop[ctr];
		}
		ctr++;
		cin.ignore(INT_MAX, '\n');
	} while (ctr < 1000);
}
