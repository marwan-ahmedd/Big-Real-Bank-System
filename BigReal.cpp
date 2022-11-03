#include "BigReal.h"

bool BigReal::checkValid(string theNum)
{
    regex input("[-+]?[0-9]*\.[0-9]*");
    return regex_match(theNum, input);
}
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
    string num = bigInteger.getNumber();
    bool valid = checkValid(num);

    if (valid){
        int pos = num.find('.');
        realPart = num.substr(0, pos);
        fractPart = num.substr(pos+1);
    }
    else{
        cout << "Invalid input.\n";
        exit(1);
    }
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
BigReal BigReal::operator+ (BigReal& other)
{
    BigReal t("0.0");
    int sn1 = sign(), sn2 = other.sign();
    string z1, z2, zCarry = "";

    if (realPart.length() > other.realPart.length()){
        for (long i = 0; i < (int)(realPart.length() - other.realPart.length()); ++i)
            z1 += '0';
        z1 += other.realPart;
        other.realPart = z1;
    }
    if (realPart.length() < other.realPart.length()){
        for (long i = 0; i < (int)(other.realPart.length() - realPart.length()); ++i)
            z2 += '0';
        z2 += realPart;
        realPart = z2;
    }
    while (zCarry.length() < (realPart.length()-1))
        zCarry += '0';
    zCarry += '1';

    while (fractPart.length() > other.fractPart.length()){
        other.fractPart += '0';
    }
    while (fractPart.length() < other.fractPart.length()){
        fractPart += '0';
    }
    string n1 = realPart + fractPart;
    string n2 = other.realPart + other.fractPart;

    if (sn1 == sn2){
        t.fractPart = addition(fractPart, other.fractPart);
        if (t.fractPart.length() > fractPart.length()){
            t.fractPart = t.fractPart.substr(1);
            string test = addition(zCarry, realPart);
            t.realPart = addition(test, other.realPart);
        }
        else{
            t.realPart = addition(realPart, other.realPart);}

        if (sn2){
            string sn = '-' + t.realPart;
            t.realPart = sn;
        }
        return t;
    }
    else{
        if (n1 >= n2){
            string sub = subtraction(realPart, other.realPart);
            int carry{0}, sum{0}; string newStr = "";
            for (int i = (int)n1.length()-1; i >= 0; --i){
                char c = n1[i], cc = n2[i];// convert from char to integer
                int num = (int)(c-'0'), nn = (int)(cc-'0');
                num -= carry;   // subtraction process and checking the carry
                if (num < nn){
                    sum = (num+10) - nn;
                    carry = 1;
                }
                else
                    sum = num - nn, carry = 0;
                sum += '0';//convert back to char
                c = (char)sum;
                newStr += sum, sum = 0;// add to result string, carefully because its reversed
            }
            if (sn1) newStr += '-';
            reverse(newStr.begin(), newStr.end());

            if (sn1){
            //if (newStr.length() == (n1.length()+1)){
                newStr += '0';
                for (int i = (int)newStr.length()-1; i > (int)(sub.length()); --i)
                    newStr[i] = newStr[i-1];
                newStr[sub.length()+1] = '.';
            ///}
            }
            else{
                newStr += '0';
                for (int i = (int)newStr.length()-1; i > (int)(sub.length()); --i)
                    newStr[i] = newStr[i-1];
                newStr[sub.length()] = '.';
            }
            int p = newStr.find('.');
            t.realPart = newStr.substr(0, p);
            t.fractPart = newStr.substr(p+1);
            return t;
        }
        else if (n1 < n2){
            string sub = subtraction(other.realPart, realPart);
            int carry{0}, sum{0}; string newStr = "";
            for (int i = (int)n2.length()-1; i >= 0; --i){
                char c = n2[i], cc = n1[i];// convert from char to integer
                int num = (int)(c-'0'), nn = (int)(cc-'0');
                num -= carry;   // subtraction process and checking the carry
                if (num < nn){
                    sum = (num+10) - nn;
                    carry = 1;
                }
                else
                    sum = num - nn, carry = 0;
                sum += '0';//convert back to char
                c = (char)sum;
                newStr += sum, sum = 0;// add to result string, carefully because its reversed
            }
            if (sn2) newStr += '-';
            reverse(newStr.begin(), newStr.end());

            if (sn2){
                newStr += '0';
                for (int i = (int)newStr.length()-1; i > (int)(sub.length()); --i)
                    newStr[i] = newStr[i-1];
                newStr[sub.length()+1] = '.';
            }
            else{
                newStr += '0';
                for (int i = (int)newStr.length()-1; i > (int)(sub.length()); --i)
                    newStr[i] = newStr[i-1];
                newStr[sub.length()] = '.';
            }
            int p = newStr.find('.');
            t.realPart = newStr.substr(0, p);
            t.fractPart = newStr.substr(p+1);
            return t;
        }
    }
}
////////////////////////////////////////////////////////////////
BigReal BigReal::operator- (BigReal& other)
{
    // Ongoing
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
