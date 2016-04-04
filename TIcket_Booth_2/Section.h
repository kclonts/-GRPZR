#pragma once
#include <string>
#include "Seat.h"
using std::string;

const int MAX_SECTIONS = 1000;

class Section
{
private:
    struct Section_item							/*section struct item definition*/
    {
        string row_name;
        int first_seat_number;
        int last_seat_number;
    };

public:
    Section(string name);
	void Section::Add_Section(string name, string row_name, int first_seat_number, int last_seat_number);

    string Get_Name() const {return name;};		/*get section name*/
    int Get_Number_of_Elements() const {return number_of_elements;};	/*get number of sections*/

    void get_section(int i,							/*get section name and range*/
                      string& name, 
                      int& first_seat_number, 
                      int& last_seat_number) const;

	Seat* Add_A_Seat(string& Row, int& Seat_number);

    void Display() const;

private:
	/*section item attributes*/
    string name;
    Section_item sections[MAX_SECTIONS];		/*collection of rows and ranges*/
	int number_of_elements;						/*number of different rows and ranges*/
	Seat* section_seats[MAX_SECTIONS];			/*seat objects in section*/
	int number_of_seats = 0;					/*number of seats per section*/
	
};
