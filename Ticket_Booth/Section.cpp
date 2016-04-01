#include "Section.h"
using namespace std;

Section::Section(string SectionName, string *RowName, int *RowStart, int *RowEnd, int RowCount):
section_name(SectionName), section_row(RowName), row_start(RowStart), row_end(RowEnd), row_count(RowCount)
{}
 
/*function displays row names and ranges per section*/
void Section::Display() const {

cout << "Section: " << section_name << endl;
   for(int i = 0; i < row_count; i++){
	cout << "Row " << *(section_row[i]) << " Seats " << *(row_start[i]) << " - " << *(row_end[i]) << "\n" << endl;
   }

}

Section::~Section(void){}	
