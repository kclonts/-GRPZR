#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Venue.h"

using namespace std;

Venue::Venue(const string& Name, 
             const Address& Address) :
    name(Name), address(Address), number_of_seat_rows(0)
{}

void Venue::Add_Row(Seat_Row* new_seat_row)
{
    if (number_of_seat_rows >= MAX_SEAT_ROWS)
    {
        throw "Venue error: too many seat rows\n";
    }

    unsigned int i = number_of_seat_rows++;
    seat_row[i] = new_seat_row;
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
