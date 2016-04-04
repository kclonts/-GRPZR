#pragma once
#include <string>
#include "Address.h"
#include "Seat_Row.h"
#include "Section.h"

class Venue
{
public:
    static const int MAX_SEAT_ROWS = 1000;
    static const int MAX_SECTIONS=100;
    static const int MAX_PERFORMANCES=100;

private:
    string name;
    const Address* address;
    const Section* sectionList[MAX_SECTIONS]; //These two may need to be changed depending on section class by TC
   // const Performance* performanceList[MAX_PERFORMANCES];
    int number_of_seat_rows=0;
    int numOfSections=0;
    int numOfPerformances=0;

public:
    const Seat_Row* seat_rows[MAX_SEAT_ROWS];
    Venue(const string& name_,
        const Address& address_);

    void Add_Seat_Row(const Seat_Row* seat_row);

    int Capacity() const;     // Number of seats

    void Display() const;
    
    void DisplayAll()const;

    int Number_of_Seat_Rows() const
    {
        return number_of_seat_rows;
    };

    const Seat_Row* Get_Seat_Row(int index) const
    {
        return seat_rows[index];
    }



};


