#pragma once
#include "tinyxml.h"
#include "Venue.h"
#include "Seat.h"
#include "Seat_Row.h"

class Venue_from_Xml
{
public:
    Venue_from_Xml() {};
    static Venue* Get_Venue(TiXmlNode* venue_node);

private:
    static Address* Get_Address(TiXmlNode* address_node);
    static void Get_Seats(TiXmlNode* seat_row_node, Venue* venue);
    static Seat_Row* Get_Seat_Row(TiXmlNode* seat_row_node);
    static Seat* Get_Seat(TiXmlNode* seat_node, const string& row_name);
};
