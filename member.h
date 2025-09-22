// member.h

#ifndef member_H
#define member_H

#include "length.h"
#include <iostream>

class member {
private:
    length height;
    int weight;
    int memberID;


public:
    member(){};
    member(int);  // for initialization with memberID
    void setHeight(int, int); 
    void setHeight(length);
    void setWeight(int);
    length getHeight() const; //not implemented yet
    int getWeight() const;

    // length operator+ (const length&);
    //length operator+ (const int&);
    friend ostream& operator<< (ostream&, const member&);
    //friend length operator+(int lhs, const length& rhs);

    // length normalize(length&); // want to alter the value of temp object, use "&"
};

#endif