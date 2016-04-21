#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "Seat_Row.h"

Seat_Row::Seat_Row(const string& Row_Name) :
                   row_name(Row_Name), number_of_seats(0)
{}


void Seat_Row::Add_Seat(const Seat* seat)
{
    if (number_of_seats == MAX_SEATS_PER_ROW)
    {
        throw "Too many seats added to row ";
    }
    seats[number_of_seats++] = seat;
}



const Seat* Seat_Row::Get_Seat(int idx) const
{
    if ((idx < 0) || (idx >= number_of_seats))
    {
        throw "Invalid idx argument passed to Get_Seat";
    }
    return seats[idx];
}

void Seat_Row::Display() const
{
    for (int i = 0; i < number_of_seats; ++i)
    {
        seats[i]->Display();
    }
}


