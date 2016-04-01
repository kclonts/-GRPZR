#pragma once
#include <iostream>
#include <string>

using namespace std;

class Section{
		
	private:
	string section_name;	
	string *section_row;	//string array for row names
	int *row_start;		//int array for row start
	int *row_end;		//row range end
	int row_count;		// number of rows in section

	public:
	Section(){};
	Section(string SectionName, string *RowName, int *RowStart, int *RowEnd, int RowCount); 
	void Display() const;
	
	~Section();


};
