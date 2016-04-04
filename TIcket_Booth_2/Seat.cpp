#include <iostream>
#include <string.h>

#include "Seat.h"
//#include "Seat_Row.h"
using namespace std;

Seat::Seat (int Seat_Number, const string& Row_Name, string Section) :
seat_number(Seat_Number),
seat_row_name(Row_Name),
section(Section)

{}


void Seat::Display() const
{
    cout << "Section" << section << "Row " << seat_row_name << " Seat " << seat_number << endl;
}
