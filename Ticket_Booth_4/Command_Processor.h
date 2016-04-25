#pragma once
#include <string>
#include "Venue.h"
#include "Menu.h"
using std::string;

class Command_Processor
{
public:
    static void Process_Commands();

private:
    enum Command_States {Initial, Venue_Selected, Done};
    static const int NR_STATES = (int) Done;
    static Menu* menus[NR_STATES];
    static Command_States command_state;
    static Venue* selected_venue;

    Command_Processor(void) {};
    static void Create_Menus();
    static void Process_Initial_State_Cmds(const string& cmd);
    static void Process_Venue_Selected_Cmds(const string& cmd);
    static void Select_Venue();
    static void Select_Show();
};
