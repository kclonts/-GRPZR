#pragma once
#include <iostream>
#include <string>
#include "Seat.h"
using namespace std;

class Section{
		
	private:
	string section_name;
	string *section_row;
	int *row_start;
	int *row_end;
	int row_count;

	public:
	Section(){};
	Section(string SectionName, string *RowName, int *RowStart, int *RowEnd, int RowCount); 
	void Display() const;
	
	~Section();


};
