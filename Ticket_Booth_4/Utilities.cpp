#include <sstream>
#include "Utilities.h"

using namespace std;

string Utilities::Format_Date_and_Time(tm when)
{
    stringstream s;
    s.fill('0');
    s << when.tm_mon+1  << "/" << when.tm_mday
         << "/" << when.tm_year + 1900;
    s << " at ";
    s.width(2);
    s << when.tm_hour << ":";
    s.width(2);
    s << when.tm_min;

    return s.str();
}

