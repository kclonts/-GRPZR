#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Address.h"

using namespace std;

Address::Address(const string& Street_Address,
                 const string& City,
                 const string& State,
                 int Zip_Code) : 
street_address(Street_Address), city(City), state(State), zip_code(Zip_Code)
{}

Address::Address() : zip_code(0)
{}

void Address::Display() const
{
    cout << street_address << endl;
    cout << city << ", " << state << " ";
    cout << zip_code << endl;
}

