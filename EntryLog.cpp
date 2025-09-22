// EntryLog.cpp

#include "Time.h"
#include "member.h"
#include "EntryLog.h"
#include <iostream>

using namespace std;


void EntryLog::setMember(member m) {
    mem = m;
} 

void EntryLog::setTimeIn(Time t) {
    time = t;
}  
void EntryLog::setTimeOut(Time t) {
    time = t;
}

ostream& operator<< (ostream& strm, const EntryLog& rhs) {
    strm << rhs.mem << rhs.time << endl;
    return strm;
}
