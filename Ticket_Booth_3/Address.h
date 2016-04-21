#pragma once

#include <string>
using std::string;

class Address
{
public:
    static const int MAX_STREET_ADDRESS = 40;
    static const int MAX_CITY = 40;
    static const int MAX_STATE = 2;

private:
    const string street_address;
    const string city;
    const string state;
    const int zip_code;

public:
    // Constructor
    Address(const string& Street_Address,
            const string& City,
            const string& State,
            int Zip_Code);

    Address();

    const string Street_Address() const {return street_address;};
    const string City() const  {return city;};
    const string State() const {return state;};
    int Zip_Code() const {return zip_code;};
    void Display() const;
};
