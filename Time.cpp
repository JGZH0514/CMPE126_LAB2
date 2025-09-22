// Time.cpp

#include "Time.h" 
#include <iostream>
#include <stdexcept> 

using namespace std;

Time::Time() {minute = 0; hour = 0;}
Time::Time(int m) {minute = m;}
Time::Time(int h, int m) {hour = h; minute = m;}

void Time::setMinute(int m) {
    if (m >= 60 || m < 0) {
        throw std::out_of_range("Minute out of range, minute values must be between 0 and 59");
    }
    minute = m;
}
void Time::setHour(int h) {
    if (h >= 24 || h < 0) {
        throw std::out_of_range("Hour out of range, hour values must be between 0 and 23");
    }
    hour = h;
}
int Time::getMinute() const {return minute;}
int Time::getHour() const {return hour;}

Time Time::operator+ (const Time& rhs) {
    Time temp(this->hour + rhs.hour, this->minute + rhs.minute);
    normalize(temp); //this->normalize(temp)
    return temp;
}

Time Time::operator+ (const int& min) {
    Time temp(this->hour, this->minute + min);
    normalize(temp);
    return temp;
}

ostream& operator<< (ostream& strm, const Time& rhs) {
    strm << "Hour: " << rhs.hour << " "; 
    strm << "Minute: " << rhs.minute << endl;
    return strm;
}

// length operator+(int lhs, const length& rhs) {
//     length temp(rhs.feet, lhs + rhs.inches);
//     temp.normalize(temp);
//     return temp;
    
    // length temp;
    // temp = rhs + lhs; // can implement this if rhs is not const 
    // temp.normalize(temp);
    // return temp;
// }

Time Time::normalize(Time& temp) {
    if(temp.minute > 59) {
        temp.hour = temp.hour + temp.minute / 60;
        temp.minute = temp.minute % 60;
    }

    if(temp.minute < 0) {
        int carry;
        carry = abs(minute) / 60;
        temp.hour = temp.hour - carry;
        temp.minute = temp.minute + (carry * 60);
    }

    if(temp.hour > 23) {
        temp.hour = temp.hour % 23;
    }

    return temp;
}
