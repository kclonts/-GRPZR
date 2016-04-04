#pragma once
#include <string>
#include <fstream>

using namespace std;

class Address
{
private:
    string street_address;
    string city;
    string state;
    int zip_code;

public:
    Address(string Street_Address,
        string City,
        string State,
        int Zip_Code);

    Address(ifstream& infile);

    void Display() const;

    int Zip_code() const
    {
        return zip_code;
    }

};