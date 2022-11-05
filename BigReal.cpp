#include "BigReal.h"

///////////////////////////////////////////////////////////////
BigReal::BigReal(double realNumber)
{
    string strNum = to_string(realNumber);

    int pos = strNum.find('.');
    realPart = strNum.substr(0, pos);
    fractPart = strNum.substr(pos+1);
}
///////////////////////////////////////////////////////////////
BigReal::BigReal(string realNumber)
{
    int pos = realNumber.find('.');
    realPart = realNumber.substr(0, pos);
    fractPart = realNumber.substr(pos+1);
}
///////////////////////////////////////////////////////////////
BigReal::BigReal (BigDecimalInt bigInteger)
{
    if (bigInteger.sign() == 0)
        realPart = '-' + bigInteger.getNumber();
    else
        realPart = bigInteger.getNumber();
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
    BigReal res("0.0");

    BigDecimalInt obj1(realPart), obj2(other.realPart);
    BigDecimalInt sum(obj1+obj2);

    while (fractPart.length() > other.fractPart.length())
        other.fractPart += '0';
    while (fractPart.length() < other.fractPart.length())
        fractPart += '0';
    string both1 = realPart + fractPart, both2 = other.realPart + other.fractPart;
    BigDecimalInt obj3(both1), obj4(both2);
    BigDecimalInt sum2(obj3+obj4);

    string s1 = sum.getNumber(), s2 = sum2.getNumber();
    bool checkLast = false;
    for (int i = 0; i < sum.size(); ++i){
        if (s2[i] != s1[i]){
            s2.insert(i+1, ".");
            checkLast = false;
            break;
        }
        if (s2[i] == s1[i])
            checkLast = true;
    }
    if (checkLast)
        s2.insert(s1.length(), ".");

    if (sum2.sign() == 0){
        string negative = "-";
        negative += s2; s2 = negative;
    }

    int pos = s2.find('.');
    res.realPart = s2.substr(0, pos);
    res.fractPart = s2.substr(pos+1);
    return res;
}
////////////////////////////////////////////////////////////////
BigReal BigReal::operator- (BigReal& other)
{
    BigReal ans("0.0");

    BigDecimalInt obj5(realPart), obj6(other.realPart);
    BigDecimalInt sum3(obj5-obj6);

    while (fractPart.length() > other.fractPart.length())
        other.fractPart += '0';
    while (fractPart.length() < other.fractPart.length())
        fractPart += '0';
    string both1 = realPart + fractPart, both2 = other.realPart + other.fractPart;
    BigDecimalInt obj7(both1), obj8(both2);
    BigDecimalInt sum4(obj7-obj8);

    string s1 = sum3.getNumber(), s2 = sum4.getNumber();
    bool checkLast = false;
    for (int i = 0; i < sum3.size(); ++i){
        if (s2[i] != s1[i]){
            s2.insert(i+1, ".");
            checkLast = false;
            break;
        }
        if (s2[i] == s1[i])
            checkLast = true;
    }
    if (checkLast)
        s2.insert(s1.length(), ".");

    if (sum4.sign() == 0){
        string negative = "-";
        negative += s2; s2 = negative;
    }

    int pos = s2.find('.');
    ans.realPart = s2.substr(0, pos);
    ans.fractPart = s2.substr(pos+1);
    return ans;
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
