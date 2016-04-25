#include <iostream>
#include <string>
#include <cassert>
#include "Menu.h"
using namespace std;

Menu::Menu(const string& prompt_) : 
    nr_commands(0), prompt(prompt_)
{}
Menu::~Menu(void)
{
    for (int i = 0; i < nr_commands; ++i)
    {
        delete commands[i];
    }
}

void Menu::Add_Command(const string& cmd)
{
    assert(nr_commands < MAX_COMMANDS);
    commands[nr_commands++] = new string(cmd);
}

const string* Menu::Get_Command(void) const
{
    int choice = 0;
    char junk[100];
    while (true)
    {
        cout << prompt << endl;
        for (int i = 0; i < nr_commands; ++i)
        {
            cout << (i+1) << ": " << *commands[i] << endl;
        }
        cout << endl;
        cout << "> ";
        cin >> choice;
        cin.clear();
        cin.getline(junk, 100);     // Clear input buffer
            
        if ((choice < 1) || (choice > nr_commands))
        {
            cout << "Invalid choice\n";
            cout << "Please try again\n\n";
            continue;
        }
        return commands[--choice];
    }
}
