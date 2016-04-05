#pragma once
#include <iostream>
#include <string>
#include "Performance.h"

using namespace std;

struct VenueSeat
{
	char row;
	int seat;

};


#ifndef VENUE_H
#define VENUE_H
class Venue
{
private:
	string v_name;
	Address venue_address;
	int capacity;
	VenueSeat v_seat;


public:
	Venue(string v_name, Address Venue_address_, int capacity_, VenueSeat v_seat_ );
	
	~Venue();

};

#endif 