#pragma once
#include <string>

using std::string;

class Seat
{
private:
    string seat_row_name;
    int seat_number;
    string section_name;

public:
    Seat (const string& Row_Name,
          int Seat_Number,
          const string& Section_Name);

    Seat() { };

    void Display() const;
};
