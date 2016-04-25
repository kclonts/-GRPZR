#pragma once
#include <ctime>

class Utilities
{
public:
    static std::string Format_Date_and_Time(tm when);

private:
    Utilities(void) {};     // Never instantiate this class
};
