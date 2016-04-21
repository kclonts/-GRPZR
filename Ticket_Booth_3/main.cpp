#include <iostream>
#include <string>
#include <cassert>
#include "tinyxml.h"
#include "Venue_from_Xml.h"
#include "Venue.h"
#include "Command_Processor.h"
using namespace std;

/*function to get all venues*/
int Get_Venues(Venue** all_venues)
{
	int count = 0;

	string filename = "Venues.xml";
	TiXmlDocument doc(filename);

	bool loadOkay = doc.LoadFile();
	if (!loadOkay)
	{
		cout << "Could not load file " << filename << endl;
		cout << "Error='" << doc.ErrorDesc() << "'. Exiting.\n";
		cin.get();
		exit(1);
	}

	TiXmlNode* venue_file_node = doc.FirstChild("venue_file");
	assert(venue_file_node != 0);


	//cout << venue_file_node->Value() << endl;  TEST

	TiXmlNode* venue_node = venue_file_node->FirstChild();
	
	while (venue_node != 0) {
																//get venue name and address from xml file
		TiXmlNode* name_node = venue_node->FirstChild();
		string venue_name = name_node->FirstChild()->Value();
		TiXmlNode* address1_node = name_node->NextSibling()->FirstChild();
		string address1 = address1_node->FirstChild()->Value();
		TiXmlNode* city_node = address1_node->NextSibling();
		string city = city_node->FirstChild()->Value();
		TiXmlNode* state_node = city_node->NextSibling();
		string state = state_node->FirstChild()->Value();
		int zip;
		TiXmlNode* zip_node = state_node->NextSibling();
		assert(zip_node != 0);
		string buffer = zip_node->FirstChild()->Value();
		istringstream(buffer) >> zip;

		Address add1(address1, city, state, zip);				//create venue address
		Venue* venue;
		venue = Venue_from_Xml::Get_Venue(venue_node);			//create sections and rows for venue

		all_venues[count++] = venue;
		venue_node = venue_node->NextSibling();					//get next venue
	}
	return count;

}


/*method to display all the venues*/
void Display_All(Venue** venues, int nr_venues)
{
	for (int i = 0; i < nr_venues; i++) {
		venues[i]->Display();
		cout<<endl;
	}
}

int main(void)
{
	cout << "This is Ticket_Booth_0\n\n";

	Venue* venues[50];
	int number_of_venues = 0;
	
	number_of_venues = Get_Venues(venues);
	Display_All(venues, number_of_venues);

	Command_Processor::Process_Commands(venues, &number_of_venues);
	cout << "\nNormal termination\n";

    cin.get();
    return 0;
}
