#include "Address.h"
#include <iostream>

Address::Address(string Street_Address,
                 string City,
                 string State,
                 int Zip_Code) :
    street_address(Street_Address),
    city(City),
    state(State),
    zip_code(Zip_Code)
{}

Address::Address(ifstream& infile)
{
    string junk;
    getline(infile, street_address);
    getline(infile, city);
    getline(infile, state);
    infile >> zip_code;
    getline(infile, junk);    // Clear newline char from input
}

void Address::Display() const
{
    cout.fill('0');
    cout << street_address << endl;
    cout << city << ", " << state << " ";
    cout.width(5);
    cout << zip_code << endl;
}
