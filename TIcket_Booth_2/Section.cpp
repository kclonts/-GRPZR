#include <iostream>
#include <cassert>
#include "Section.h"

using namespace std;
Section::Section(string Name) :				/*section instantiated with name only*/
  name(Name), number_of_elements(0)
{}


/*method to add a new section
Parameters:	name, range
Result: new section created and added to list of sections
*/
void Section::Add_Section(string name, string row_name, int first_seat_number, int last_seat_number) 
{
	name = name;

	/*create and store list of ranges*/
    assert(number_of_elements < MAX_SECTIONS);
	Section_item sec = { row_name, first_seat_number, last_seat_number };
	sections[number_of_elements++] = sec;

	/*add seat objects to collection for range*/	
	for (int i = number_of_elements-1; i < number_of_elements; i++) {
		for (int k = sections[i].first_seat_number; k <= sections[i].last_seat_number; k++) {
			section_seats[number_of_seats++] = Add_A_Seat(sections[i].row_name, k);   /*add the seat to the array of seats for the section*/
		}
	}
}

void Section::get_section(int i, 
                                  string& name_, 
                                  int& first_seat_number_, 
                                  int& last_seat_number_) const
{
    assert(i >= 0);
    assert(i < number_of_elements);
    name_ = sections[i].row_name;
    first_seat_number_ = sections[i].first_seat_number;
    last_seat_number_ = sections[i].last_seat_number;
}

/*function to add a seat to a collection of seat objects
	Required: row name and number
	Action: object created and stored to array
*/
Seat* Section::Add_A_Seat(string& Row, int& Seat_number)
{
	Seat* s1 = new Seat(Row, Seat_number);
	return s1;
}


void Section::Display() const
{
    /*Display seat and section object attributes*/
    for (int i = 0; i < number_of_seats ; ++i)
    {
        section_seats[i]->Display();
		cout << " Section\t" << Get_Name() << endl;
    }
    cout << endl;
}
