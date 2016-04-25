#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Seat.h"
#include "Seat_Row.h"

using namespace std;

Seat::Seat(const Seat_Row* seat_row_,
    int Seat_Number,
    const string& Section_Name) :
    seat_row(seat_row_),
    seat_number(Seat_Number),
    section_name(Section_Name)
{}

void Seat::Display() const
{
    cout << "Row " << seat_row->Row_Name() << " ";
    cout << "Seat " << seat_number << " ";
    cout << "Section " << section_name << endl;
}

