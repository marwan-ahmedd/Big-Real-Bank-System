#include "BigReal.h"


////////////////////////////////////////////////////////////////
BigReal :: BigReal(const BigReal& other)
{
    this->realPart = other.realPart;
    this->fractPart = other.fractPart;
}
////////////////////////////////////////////////////////////////
BigReal :: BigReal(BigReal&& other) : realPart(move(other.realPart)), fractPart(move(other.fractPart))
{}
////////////////////////////////////////////////////////////////
BigReal& BigReal :: operator= (BigReal& other)
{
    this->realPart = other.realPart;
    this->fractPart = other.fractPart;
    return *this;
}
////////////////////////////////////////////////////////////////
BigReal& BigReal :: operator= (BigReal&& other)
{
    this->realPart = move(other.realPart);
    this->fractPart = move(other.fractPart);
    return *this;
}
////////////////////////////////////////////////////////////////
bool BigReal :: operator< (BigReal anotherReal)
{
    BigReal result = *this - anotherReal;

    if (result.sign())
        return true;

    return false;
}
////////////////////////////////////////////////////////////////
bool BigReal :: operator> (BigReal anotherReal)
{
    BigReal result = *this - anotherReal;

    if (result.sign())
        return false;

    return true;
}
////////////////////////////////////////////////////////////////
bool BigReal :: operator== (BigReal anotherReal)
{
    // TODO
}
////////////////////////////////////////////////////////////////
int BigReal :: size()
{
    return realPart.length() + fractPart.length();
}
////////////////////////////////////////////////////////////////
int BigReal :: sign()
{
    if (realPart[0] == '-')
    {
        realPart = realPart.substr(1);
        return 1;
    }
    else if (realPart[0] == '+')
    {
        realPart = realPart.substr(1);
        return 0;
    }
    return 0;
}
////////////////////////////////////////////////////////////////
ostream &operator<< (ostream& out, BigReal& num)
{
    if (num.realPart != "" and num.fractPart != "")
        out << num.realPart + '.' + num.fractPart << '\n';
    return out;
}
////////////////////////////////////////////////////////////////
istream &operator>> (istream& in, BigReal& num)
{
    string msg;
    cout << "Enter number: ";
    in >> msg;

    int end = msg.find('.');

    num.realPart = msg.substr(0, end);
    num.fractPart = msg.substr(end + 1, -1);

    return in;
}
