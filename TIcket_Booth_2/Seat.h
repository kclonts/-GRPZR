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
    Seat(int Seat_Number, const string& Row_Name, string Section);
    
    void Display() const;
};
