#pragma once
#include <string.h>
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"

using std::string;

class Venue
{
public:
    static const int MAX_VENUE_NAME = 40;
    static const int MAX_SEAT_ROWS = 1000;

private:
    string name;
    Address address;
    Seat_Row* seat_row[MAX_SEAT_ROWS];
    int number_of_seat_rows;

public:
    Venue(const string& Name, 
          const Address& Address);
    Venue() {};

    void Add_Row(Seat_Row* new_seat_row);

    int Capacity() const;     // Number of seats

    const Seat_Row* Get_Seat_Row(int index) const 
        {return seat_row[index];};

    int Get_Number_of_Seat_Rows() const 
        {return number_of_seat_rows;};

    void Display() const;
    void Display_All() const;

    string Name() const {return name;};

    bool operator<(const Venue& other) const;
};
