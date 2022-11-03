#include "BigReal.h"

bool BigReal::checkValid(string theNum)
{
    regex input("[-+]?[0-9]*\.[0-9]*");
    return regex_match(theNum, input);
}
///////////////////////////////////////////////////////////////
BigReal::BigReal(double realNumber)
{
    string strNum = to_string(realNumber);
    bool valid = checkValid(strNum);

    if (valid){
        int pos = strNum.find('.');
        realPart = strNum.substr(0, pos);
        fractPart = strNum.substr(pos+1);
    }
    else{
        cout << "Invalid input.\n";
        exit(1);
    }
}
///////////////////////////////////////////////////////////////
BigReal::BigReal(string realNumber)
{
    bool valid = checkValid(realNumber);

    if (valid){
        int pos = realNumber.find('.');
        realPart = realNumber.substr(0, pos);
        fractPart = realNumber.substr(pos+1);
    }
    else{
        cout << "Invalid input.\n";
        exit(1);
    }
}
///////////////////////////////////////////////////////////////
BigReal::BigReal (BigDecimalInt bigInteger)
{
    realPart = bigInteger.getNumber();
    fractPart = "0";
}
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
    this->realPart = other.realPart;    // makes a copy of the other number's real part and assigns it to the lValue
    this->fractPart = other.fractPart;  // makes a copy of the other number's fraction part and assigns it to the lValue
    return *this;
}
////////////////////////////////////////////////////////////////
BigReal& BigReal :: operator= (BigReal&& other)
{
    this->realPart = move(other.realPart);    // assigns the value of the other's real part to the lValue and deletes the other's realPart
    this->fractPart = move(other.fractPart);  // assigns the value of the other'fraction part to the lValue and deletes the other's fraction
    return *this;
}
////////////////////////////////////////////////////////////////
BigReal BigReal::operator+ (BigReal& other)
{
    
}
////////////////////////////////////////////////////////////////
BigReal BigReal::operator- (BigReal& other)
{
    // Ongoing
}
////////////////////////////////////////////////////////////////
bool BigReal :: operator< (BigReal anotherReal)
{
    BigReal result = *this - anotherReal;   // subtract the number with the anotherReal to check which of them is bigger

    if (result.sign())
        return true;

    return false;
}
////////////////////////////////////////////////////////////////
bool BigReal :: operator> (BigReal anotherReal)
{
    BigReal result = *this - anotherReal; // subtract the number with the anotherReal to check which of them is bigger

    if (result.sign())
        return false;

    return true;
}
////////////////////////////////////////////////////////////////
bool BigReal :: operator== (BigReal anotherReal)
{
    return ((*this + anotherReal) == (*this + *this));  // check if the number + anotherReal equals to 2 * the number
}
////////////////////////////////////////////////////////////////
int BigReal :: size()
{
    return realPart.length() + fractPart.length();  // return size of number
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
