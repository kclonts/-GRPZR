#pragma once
#include <string.h>
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Seating_Section.h"

using std::string;

class Venue
{
public:
	static const int MAX_VENUE_NAME = 40;
	static const int MAX_SEAT_ROWS = 1000;
	static const int MAX_SEATING_SECTIONS = 1000;

private:
	string name;
	Address address;
	Seat_Row* seat_row[MAX_SEAT_ROWS];
	int number_of_seat_rows;
	Seating_Section* seating_section[MAX_SEATING_SECTIONS];
	int number_of_seating_sections;


public:
	Venue(const string& Name,
		const Address& Address);
	Venue() {};

	void Add_Row(const string& Row_Name,
		int Number_of_Seats);

	void Add_Seating_Section(Seating_Section* new_seating_section);


	int Capacity() const;     // Number of seats

	const Seat_Row* Get_Seat_Row(int index) const
	{
		return seat_row[index];
	};

	int Get_Number_of_Seat_Rows() const
	{
		return number_of_seat_rows;
	};


	const Seating_Section* Get_Seating_Section(int index) const
	{
		return seating_section[index];
	};

	int Get_Number_of_Seating_Sections() const
	{
		return number_of_seating_sections;
	};


	void Display() const;
	void Display_All() const;

	string Name() const { return name; };

	bool operator<(const Venue& other) const;
};
