#include <iostream>
#include <string>
#include <cassert>
#include "Seat_Row.h"
using namespace std;

Seat_Row::Seat_Row(const string& Row_Name) :
    row_name(Row_Name),
    number_of_seats(0)
{}

void Seat_Row::Add_Seat(const Seat* new_seat)
{
    assert(number_of_seats < MAX_SEATS_PER_ROW);
    seats[number_of_seats++] = new_seat;
}

void Seat_Row::Display() const
{
    cout << "Row " << row_name << " has "
        << number_of_seats << " seats" << endl;
    for (int i = 0; i < number_of_seats; ++i)
    {
        cout << "\t";		// Indent the Seat description
        seats[i]->Display();
    }
}

