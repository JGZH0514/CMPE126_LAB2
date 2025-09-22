// member.cpp

#include "length.h"
#include "member.h"
#include <iostream>

using namespace std;

member::member(int ID) {memberID = ID;}

void member::setHeight(int f, int i) {height.setFeet(f); height.setInches(i);}
void member::setHeight(length l) {height = l;}
void member::setWeight(int w) {weight = w;}

length member::getHeight() const {return height;}
int member::getWeight() const {return weight;}

ostream& operator<< (ostream& strm, const member& rhs) {
    strm << "MemberID: " << rhs.memberID << endl; 
    strm << "Height: " << rhs.height.getFeet() << " feet " << rhs.height.getInches() << " inches" << endl;
    strm << "Weight: " << rhs.weight << endl;
    return strm;
}
