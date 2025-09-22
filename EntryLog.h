// EntryLog.h

#ifndef EntryLog_H
#define EntryLog_H

#include "Time.h"
#include "member.h"
#include <iostream>

using namespace std;

class EntryLog {
private:
    member mem;
    Time time;

public:
    EntryLog(){};
    void setMember(member); // for initialization with member object
    void setTimeIn(Time);  
    void setTimeOut(Time); //

    friend ostream& operator<< (ostream&, const EntryLog&);

};

#endif