// length.cpp

#include "length.h"
#include <iostream>
#include <stdexcept> 

using namespace std;

length::length() {feet = 0;inches = 0;}
length::length(int f) {feet = f; inches = 0;}
length::length(int f, int i) {
    feet = f; 
    inches = i;
    if (i > 12 || i < 0) {
        cout << "Normalizing...." << endl;
        normalize(*this);
    }
}

void length::setFeet(int f) {feet = f;}
void length::setInches(int i) {
    if (i > 11) {
        char ans; 

        cout << "Inches cannot be greater than 11. Normalize? (Y/N)" << endl;
        cin >> ans;
        if (ans == 'Y' || ans == 'y') {
            // int carry = i / 12;
            // int rem = i % 12;
            // this->feet += carry;
            // this->inches = rem; 
            // return; // exit function when i is normalized (dont continue to inches = i;)

            length temp(this->feet, i); // automatically normalized in constructor
            *this = temp;   
            return;
        }

        else {
            throw std::out_of_range("Hour out of range, inches values must be between 0 and 11");
        }
    }
    inches = i; //if not > 11, simply set i as inches
}
int length::getFeet() const {return feet;}
int length::getInches() const {return inches;}

length length::operator+ (const length& rhs) {
    length temp(this->feet + rhs.feet, this->inches + rhs.inches); // autonomatically normalized in constructor
    // normalize(temp); //this->normalize(temp)
    return temp;
}

length length::operator+ (const int& inches) {
    length temp(this->feet, this->inches + inches); // autonomatically normalized in constructor
    // normalize(temp);
    return temp;
}

ostream& operator<< (ostream& strm, const length& rhs) {
    strm << "Height: " << rhs.feet << " feet " << rhs.inches << " inches" << endl;
    return strm;
}

length operator+(int lhs, const length& rhs) {
    length temp(rhs.feet, lhs + rhs.inches); // autonomatically normalized in constructor
    // temp.normalize(temp);
    return temp;
    
    // length temp;
    // temp = rhs + lhs; // can implement this if rhs is not const 
    // temp.normalize(temp);
    // return temp;
}

length length::normalize(length& temp) {
    if(temp.inches > 11) {
        temp.feet = temp.feet + temp.inches / 12;
        temp.inches = temp.inches % 12;
    }

    if(temp.inches < 0) {
        int borrow;
        borrow = -temp.inches / 12;
        temp.feet = temp.feet - borrow;
        temp.inches = temp.inches + (borrow * 12);
    }

    return temp;
}
