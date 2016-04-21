#include <iostream>
#include <fstream>
#include "Command_Processor.h"
using namespace std;

Venue** Command_Processor::venues = 0;
int* Command_Processor::nr_venues = 0;
Venue* Command_Processor::selected_venue = 0;

Command_States Command_Processor::command_state = Initial;

Menu* Command_Processor::menus[NR_CMD_STATES];

void Command_Processor::Create_Menus()
{
    // Menu for Initial command state
    Menu* menu = new Menu("Enter command number");
    menu->Add_Command("Select Venue");
    //menu->Add_Command("Add State");
    menu->Add_Command("Quit");
    menus[0] = menu;

    // Menu for State Selected
    menu = new Menu("Enter command number");
    menu->Add_Command("Display Venue");
    menu->Add_Command("Select Show");
    menu->Add_Command("Change Venue");
    menu->Add_Command("Return to Main");
    menus[1] = menu;
}

//void Command_Processor::Process_Commands()
//{
//    cout << "Process_Commands starting\n";
//
//    while (command_state != Done)
//    {
//        // Execute next command
//        cout << "Process_Commands running\n";
//        command_state = Done;
//    }
//
//    cout << "Process_Commands  exiting\n";
//}

void Command_Processor::Process_Commands(Venue** venues_,
                                         int* nr_venues_)
{
    cout << "Process commands starting\n";

    venues = venues_;
    nr_venues = nr_venues_;

    Create_Menus();

    while (command_state != Done)
    {
        if (command_state == Venue_Selected)
        {
            cout << "Selected Venue is "
                 << selected_venue->Name() << endl;
        }
        const string* cmd = menus[command_state]->Get_Command();

        switch (command_state)
        {
        case Initial:   Process_Command_0(*cmd);
            break;

        case Venue_Selected:    Process_Command_1(*cmd);
            break;

        case Done:  break;      // Can't happen
        }
    }

    cout << "Command_Processor exiting\n";
}

// Process command in Initial command state
void Command_Processor::Process_Command_0(const string& cmd)
{
    if (cmd == "Select Venue")
    {
        // Select state
        //cout << "Select State command\n";
        Select_Venue();
        command_state = Venue_Selected;
    }
//    else if (cmd == "Add State")
//    {
//        // Add state
//        //cout << "Add State command\n";
//        Add_State();
//        command_state = Venue_Selected;
//    }
    else
    {
        //cout << "Quit command\n";
        Output_XML();
        command_state = Done;
    }
}

//City* Command_Processor::Get_City()
//{
//    string name;
//    cout << "City name: ";
//    getline(cin, name);
//    City* city = new City(name);
//    return city;
//}

// Process command in State Selected command state
void Command_Processor::Process_Command_1(const string& cmd)
{
    if (cmd == "Display Venue")
    {
        // Add City
        //cout << "Add City command\n";
        
        selected_venue->Display_All();
    }
    else if (cmd == "Select Show")
    {
        cout<<"Select_Show Called"<<endl;
        //command_state = Initial;
    }
    else if(cmd=="Change Venue")
    {
        //I'm just adjusting the processor calm down guys I know TC has this
    }
    else
    {
        //cout << "Quit command\n";
        //Output_XML();
        command_state = Venue_Selected;
    }
}

void Command_Processor::Select_Venue()
{
    Menu* menu = new Menu("Select Venue");
    for (int i = 0; i < *nr_venues; ++i)
    {
        menu->Add_Command(venues[i]->Name());
    }

    const string* venue_name = menu->Get_Command();

    // Find state with this name
    for (int i = 0; i < *nr_venues; ++i)
    {
        if (venues[i]->Name() == *venue_name)
        {
            selected_venue = venues[i];
            command_state = Venue_Selected;
            return;
        }
    }
    // Should never reach this point.
    cout << "Error in Command_Processor::Select_Venue()\n";
}

//void Command_Processor::Add_State()
//{
//    string state_name;
//    string capital_name;
//    cout << "State name: ";
//    getline(cin, state_name);
//    cout << "Capital city name: ";
//    getline(cin, capital_name);
//    City* capital = new City(capital_name);
//    State* state = new State(state_name, *capital);
//    delete capital;
//    states[(*nr_states)++] = state;
//    selected_state = state;
//}

void Command_Processor::Output_XML()
{
    ofstream outfile;
    outfile.open("venues2.xml");
    if (!outfile.is_open())
    {
        cout << "Failed to open file for output\n";
        return;
    }

    outfile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    outfile << "<USA>\n";
    for (int i = 0; i < *nr_venues; ++i)
    {
		;// venues[i]->Output_XML(outfile);
    }
    outfile << "</USA>\n";
    outfile.close();
    cout << "File svenues2.xml written\n";
}

