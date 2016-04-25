#include <iostream>
#include <vector>
#include "Venue.h"
#include "Venues_from_Xml.h"
#include "Command_Processor.h"
using namespace std;

int main(void)
{
    cout << "This is Ticket Booth 1\n\n";

    Venues_from_Xml::Get_Venues();
    
    for (int i = 0; i < Venues_from_Xml::nr_venues; ++i)
    {
        Venues_from_Xml::venues[i]->Display_All();
        cout << endl << "--------------------------" << endl;
    }

    Command_Processor::Process_Commands();

    cout << "Normal termination\n";
    cin.get();
    return 0;
}
