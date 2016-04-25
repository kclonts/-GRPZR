#pragma once
#include <string>
using std::string;

class Seat_Row;     // Incomplete declaration

class Seat
{
private:
    const Seat_Row* seat_row;
    int seat_number;
    string section_name;

public:
    Seat(const Seat_Row* seat_row,
        int Seat_Number,
        const string& Section_Name);

    Seat() { };

    void Display() const;
};
