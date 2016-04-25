#pragma once
#include <vector>
#include "tinyxml.h"
#include "Venue.h"
#include "Seat.h"
#include "Seat_Row.h"

class Venues_from_Xml
{
public:
    static Venue** venues;
    static int nr_venues;
    static void Get_Venues(void);

private:
    Venues_from_Xml(void) {};   // Never instantiate this class

    static Venue* Get_Venue(TiXmlNode* venue_node);
    static Address* Get_Address(TiXmlNode* address_node);
    static void Get_Seats(TiXmlNode* seat_row_node, Venue* venue);
    static Seat_Row* Get_Seat_Row(TiXmlNode* seat_row_node);
    static Seat* Get_Seat(TiXmlNode* seat_node, const Seat_Row* seat_row);
};
