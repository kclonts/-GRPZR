#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Venue.h"

using namespace std;

Venue::Venue(const string& Name,
	const Address& Address) :
	name(Name), address(Address), number_of_seat_rows(0),
	number_of_seating_sections(0)
{}

void Venue::Add_Row(const string& Row_Name,
	int Number_of_Seats)
{
	if (number_of_seat_rows >= MAX_SEAT_ROWS)
	{
		throw "Venue error: too many seat rows\n";
	}

	unsigned int i = number_of_seat_rows++;
	seat_row[i] = new Seat_Row(Row_Name, Number_of_Seats); //creating an array of seat_row
}

void Venue::Add_Seating_Section(Seating_Section* new_seating_section)
{
	if (number_of_seating_sections >= MAX_SEATING_SECTIONS)
	{
		throw "Venue error: too many seating sections\n";
	}
	unsigned int i = number_of_seating_sections++;
	seating_section[i] = new_seating_section;  // creating array of section


}



// Return number of seats
int Venue::Capacity() const
{
	int count = 0;
	for (int i = 0; i < number_of_seat_rows; ++i)
	{
		count += seat_row[i]->Number_of_Seats();
	}
	return count;
}

void Venue::Display() const
{
	cout << name << endl;
	address.Display();
}

void Venue::Display_All() const
{
	Display();
	for (int i = 0; i < number_of_seat_rows; ++i)
	{
		seat_row[i]->Display();
	}

	cout << "\nSeating Sections: \n";
	for (int i = 0; i < number_of_seating_sections; ++i)
	{
		seating_section[i]->Display();
	}

}


bool Venue::operator<(const Venue& other) const
{
	if (this->address.Zip_Code() < other.address.Zip_Code())
	{
		return true;
	}

	if (this->address.Zip_Code() > other.address.Zip_Code())
	{
		return false;
	}

	// Zip Codes are equal.
	return this->name < other.name;
}
