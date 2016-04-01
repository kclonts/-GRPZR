//need section class

#include <iostream>
#include "Seat.h"

using namespace std;

Seat::Seat(int Seat_Number) :
seat_number(Seat_Number)
{}

void Seat::Display() const
{
    cout << "Seat " << seat_number << endl;
}
