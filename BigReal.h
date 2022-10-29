#ifndef _BIGREAL_H
#define _BIGREAL_H
#include <iostream>
#include "BigDecimal/BigDecimalIntClass.h"

using namespace std;

class BigReal
{
    private:
        double num;
        string realPart;
        string fractPart;

    public:
        BigReal (double realNumber = 0.0);
        BigReal (string realNumber);
        BigReal (BigDecimalInt bigInteger);
        BigReal (const BigReal& other);
        BigReal (BigReal&& other);
        BigReal& operator= (BigReal& other);
        BigReal& operator= (BigReal&& other);

        BigReal operator+ (BigReal& other);
        BigReal operator- (BigReal& other);

        bool operator< (BigReal anotherReal);
        bool operator> (BigReal anotherReal);
        bool operator== (BigReal anotherReal);

        int size();
        int sign();

        friend ostream& operator<<(ostream& out, BigReal num);
        friend istream& operator>>(istream& in, BigReal& num);
};

#endif