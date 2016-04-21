#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Seat.h"
#include "Seat_Row.h"

using namespace std;

Seat::Seat (const string& Row_Name,
            int Seat_Number,
            const string& Section_Name) :
        seat_row_name(Row_Name),
        seat_number(Seat_Number),
        section_name(Section_Name)
{}



void Seat::Display() const
{
    cout << "Row " << seat_row_name << " ";
    cout << "Seat " << seat_number << " ";
    cout << "Section " << section_name << endl;
}

