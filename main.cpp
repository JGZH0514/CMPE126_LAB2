// name: Jeriel Goh
// main.cpp

#include  <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "length.h"
#include "member.h"
#include "Time.h"
#include "EntryLog.h"

using namespace std; 

int main() {

    length h1;          // h1 initialized to 0 feet 0 inches
    length h2(3);       // h2 initialized to 3 feet 0 inches
    length h3(5, 19);   // h3 initialized to 5 feet 19 inches
    int inches = 10;
    cout << h1;
    cout << h2 << h3;
    cout << h2 + h3;
    h1 = h3 + inches;
    cout << h1;

    cout << inches + h3;

    cout << endl;

//-----------------------------------Part 2 (member)--------------------------
    int memberID = 1000;
    member m1(memberID);  // Note that there should be no default value of memberID
    m1.setHeight(5, 20);   // Sets the height field to 6 feet and 8 inches
    m1.setWeight(150);    // Sets the weight field to 150 lbs
    cout << m1;           // Outputs member information in a suitable format

    length h(6, 20);
    m1.setHeight(h);      // Sets the height field to values from h
    cout << m1;

    cout << endl;

//----------------------------------Part 3 (Time)--------------------------------
    Time t1;        // t1 initialized to 0 hour 0 minute, i.e., 12:00
    Time t2(3);     // t2 initialized to 3 hour 0 minute, i.e., 03:00
    Time t3(5,10);  // t3 initialized to 5 hour 10 minute, i.e., 05:10

    int minute = 10;
    cout << t1;
    cout << t2 << t3;

    cout << endl;

//----------------------------------Part 4 (EntryLog)--------------------------------

    EntryLog log;
    log.setMember(m1);
    Time timeIn(10, 15);
    Time timeOut = timeIn + 90; 
    log.setTimeIn(timeIn);
    log.setTimeOut(timeOut);
    cout << log;

    cout << endl;

    return 0;
}