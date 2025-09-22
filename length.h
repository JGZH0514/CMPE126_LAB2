// length.h

#ifndef length_H
#define length_H

#include <iostream>

using namespace std;

class length {
private:
    int feet;
    int inches;

public:
    length();
    length(int); 
    length(int, int);
    void setFeet(int);
    void setInches(int);
    int getFeet() const;
    int getInches() const;

    length operator+ (const length&);
    length operator+ (const int&);
    friend ostream& operator<< (ostream&, const length&);
    friend length operator+(int lhs, const length& rhs);

    length normalize(length&); // want to alter the value of temp object, use "&"
};

#endif