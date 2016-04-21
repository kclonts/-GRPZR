#pragma once
#include <string>
#include "Seat.h"

using std::string;

class Seat_Row
{
public:
    static const int MAX_ROW_NAME_LENGTH = 5;
    static const int MAX_SEATS_PER_ROW = 1000;

private:
    string row_name;
    const Seat* seats[MAX_SEATS_PER_ROW];
    int  number_of_seats;

public:
    Seat_Row(const string& Row_Name);
    void Add_Seat(const Seat* seat);
    void Display() const;

    string Row_Name() const {return row_name;};
    int Number_of_Seats() const {return number_of_seats;};
    const Seat* Get_Seat(int seat_nr) const;
};
