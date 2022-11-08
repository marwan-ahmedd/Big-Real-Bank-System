#include <iostream>
#include "BigReal.h"
using namespace std;

int main()
{
    BigReal a("-16125.3"), b("3237.0001");
    cout << (a + b) << " " << (a - b) << "\n";

    BigReal c("-242.595"), d("-4835.2");
    cout << (c + d) << " " << (c - d) << "\n";

    BigReal e(23.42), f(-99.2003);
    cout << (e + f) << " " << (e - f) << "\n";

    BigDecimalInt gg("902"), hh("320");
    BigReal g(gg), h(hh);
    cout << (g + h) << " " << (g - h) << "\n";

    BigReal j("23.24"), k("9223.99");
    cout << (j + k) << " " << (j - k) << "\n";

    return 0;
}
