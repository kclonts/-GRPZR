//need section class

#pragma once
#include <string>
using namespace std;

class Seat
{    
    
private:
    string section;
    string seat_row_name;
    int seat_number;
    
public:
    Seat(string Section, string Row_Name, int Seat_Number);
    
    void Display() const;
};
