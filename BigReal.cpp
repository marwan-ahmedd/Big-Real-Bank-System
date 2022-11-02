#include "BigReal.h"




////////////////////////////////////////////////////////////////
bool BigReal ::operator< (BigReal anotherReal)
{
    BigReal result = *this - anotherReal;

    if (result.sign())
        return true;

    return false;
}
////////////////////////////////////////////////////////////////
bool BigReal ::operator> (BigReal anotherReal)
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
int BigReal ::sign()
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
ostream &operator<< (ostream &out, BigReal& num)
{
    out << num.realPart + '.' + num.fractPart;
    return out;
}
////////////////////////////////////////////////////////////////
istream &operator>> (istream &in, BigReal &num)
{
    string msg;
    cout << "Enter number: ";
    in >> msg;

    int end = msg.find('.');

    num.realPart = msg.substr(0, end);
    num.fractPart = msg.substr(end + 1, -1);

    return in;
}
