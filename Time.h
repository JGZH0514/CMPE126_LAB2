// Time.h

#ifndef Time_H
#define Time_H

#include <iostream>

using namespace std;

class Time {
private:
    int minute;
    int hour;

public:
    Time();
    Time(int);  // for initialization with minute
    Time(int, int); // for intialization with hour and minute
    void setMinute(int); 
    void setHour(int);
    int getMinute() const;
    int getHour() const;

    Time operator+ (const Time&);
    Time operator+ (const int&);
    friend ostream& operator<< (ostream&, const Time&);

    Time normalize(Time&); // want to alter the value of temp object, use "&"
};

#endif