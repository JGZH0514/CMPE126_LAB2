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

    friend ostream& operator<< (ostream&, const member&);
};

#endif