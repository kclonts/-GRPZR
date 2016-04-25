#include <iostream>
#include "Command_Processor.h"
#include "Menu.h"
#include "Venues_from_Xml.h"

using namespace std;

Command_Processor::Command_States 
Command_Processor::command_state = Initial;

Menu* Command_Processor::menus[NR_STATES];
Venue* Command_Processor::selected_venue = 0;

void Command_Processor::Create_Menus()
{
    // Menu for Initial command state
    Menu* menu = new Menu("Enter command number:\n");
    menu->Add_Command("Select Venue");
    menu->Add_Command("Quit");
    menus[0] = menu;

    // Menu for State Selected command state
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Display Venue");
    menu->Add_Command("Select Show");
    menu->Add_Command("Change Venue");
    menu->Add_Command("Quit");
    menus[1] = menu;
}

void Command_Processor::Select_Venue()
{
    Menu* menu = new Menu("Select Venue");

    for (int i = 0; i < Venues_from_Xml::nr_venues; ++i)
    {
        Venue* v = Venues_from_Xml::venues[i];
        if (v == 0)
        {
            break;
        }
        menu->Add_Command(v->Name());
    }   

    menu->Add_Command("Cancel");

    const string* venue_name = menu->Get_Command();

    // Find venue with this name
    for (int i = 0; i < Venues_from_Xml::nr_venues; i++)
    {
        Venue* v = Venues_from_Xml::venues[i];

        if (v->Name() == *venue_name)
        {
            selected_venue = v;
            command_state = Venue_Selected;
            delete menu;
            return;
        }
    }

    // Cancel 
    command_state = Initial;
}


void Command_Processor::Process_Initial_State_Cmds(const string& cmd)
{
    if (cmd == "Select Venue")
    {
        Select_Venue();
    }
    else       // Quit command
    {
        command_state = Done;
    }
}

void Command_Processor::Select_Show()
{
    cout << "\nSelect_Show called\n";
}

void Command_Processor::Process_Venue_Selected_Cmds(const string& cmd)
{
    if (cmd == "Display Venue")
    {
        selected_venue->Display_All();
    }
    else if (cmd == "Select Show")
    {
        Select_Show();
    }

    else if (cmd == "Change Venue")
    {
        command_state = Initial;
    }

    else      // Quit command
    {
        command_state = Done;
    }
}


void Command_Processor::Process_Commands()
{
    cout << "Process_Commands starting\n";

    Create_Menus();

    while (command_state != Done)
    {
        const string* cmd;

        switch (command_state)
        {
        case Initial:       cmd = menus[command_state]->Get_Command();
                            Process_Initial_State_Cmds(*cmd);
                            break;

        case Venue_Selected: cout << endl << "Selected venue is "
                                  << selected_venue->Name() << endl;
                             cmd = menus[command_state]->Get_Command();
                             Process_Venue_Selected_Cmds(*cmd);
                             break;

        case Done:  break;   // Can't happen
        }
    }

    cout << "Process_Commands exiting\n";
}

