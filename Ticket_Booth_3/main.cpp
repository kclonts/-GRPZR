#include <iostream>
#include <string>
#include <cassert>
#include "tinyxml.h"
#include "Venue_from_Xml.h"
#include "Venue.h"
using namespace std;

int main(void)
{
    Venue* venue;

    cout << "This is Ticket_Booth_0\n\n";
    string filename = "Venue.xml";
    TiXmlDocument doc(filename);

    bool loadOkay = doc.LoadFile();
    if (!loadOkay)
    {
        cout << "Could not load file " << filename << endl;
        cout << "Error='" << doc.ErrorDesc() <<"'. Exiting.\n";
        cin.get();
        exit( 1 );
    }

    TiXmlNode* venue_file_node = doc.FirstChild("venue_file");
    assert(venue_file_node != 0);
    //cout << venue_file_node->Value() << endl;

    TiXmlNode* venue_node = venue_file_node->FirstChild();
    assert(venue_node != 0);
    //cout << venue_node->Value() << endl;
    
    venue = Venue_from_Xml::Get_Venue(venue_node);

    venue->Display_All();
    cin.get();
    return 0;
}
