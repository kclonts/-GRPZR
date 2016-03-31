//need section class

#include <iostream>
#include "Seat.h"

using namespace std;

Seat::Seat(string Section, string Row_Name,
           int Seat_Number) :
section(Section),
seat_row_name(Row_Name),
seat_number(Seat_Number)
{}

void Seat::Display() const
{
    cout << "Section" << section << "Row " << seat_row_name << " Seat " << seat_number << endl;
}
