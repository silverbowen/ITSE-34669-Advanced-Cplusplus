/* Topic 08 = Fraction Sort
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

#include "fraction.h"
using namespace std;

fraction::fraction()
{
    numer = 0;
    denom = 1; // constructor
}

fraction::fraction(int num, int den)
{
    if(num>=0)
        numer = num;
    else
        numer = 0;
    if (den>=1)
        denom = den;
    else
        denom = 1; // overloaded constructor
}

fraction::fraction(const fraction &other)
{
    numer = other.numer;
    denom = other.denom; //copy constructor
}

fraction& fraction::operator=(const fraction &other)
{
    if (this == &other) return *this; // handle self-assignment
    {
        numer = other.numer;
        denom = other.denom;  // overloaded assignment operator
    }
    return *this;
}

void fraction::print() // prints (to cout) a visual form of the fraction, i.e. x/y
{
    cout << numer << "/" << denom << endl;
}

bool fraction::reducible() // returns a bool indicating value can/cannot be reduced
{
    return (GCD(numer,denom) > 1);
}

void fraction::reduceMe() // ensures that this instance is fully reduced
{
    int gcd = GCD(numer,denom);
    this->numer = numer/gcd;
    this->denom = denom/gcd;
}

fraction fraction::reduce() // returns a new fraction, fully-reduced version of original
{
    int gcd = GCD(numer,denom);
    fraction x = fraction(numer/gcd, denom/gcd); // uses overridden assignment operator
    return x;  // when this ends, the explicit destructor will be called on x
}

int fraction::getNumer()
{
    return numer;
}
int fraction::getDenom()
{
    return denom;
}
void fraction::setNumer(int num)
{
    numer = num;
}
void fraction::setDenom(int den)
{
    denom = den;
}

void fraction::setBoth(int num, int den)
{
    setNumer(num);
    setDenom(den);
}

fraction add(fraction x, fraction y) // non-member function to return a new
{                                    // fraction containing the sum of two others
    int xDen = x.getDenom();
    int yDen = y.getDenom();
    int lcm = LCM(xDen, yDen);          // it would be trivial to implement
    int factor1 = lcm / xDen;           // reduceMe here if desired.
    int factor2 = lcm / yDen;
    int num = (x.getNumer() * factor1) + (y.getNumer() * factor2);
    fraction z = fraction (num, lcm);
    return z;
}

bool lessThan(fraction x, fraction y) // non-member function returning a bool
{                                     // indicating if x < y
    int xDen = x.getDenom();
    int yDen = y.getDenom();
    int lcm = LCM(xDen, yDen);           // same code as add, mostly
    int factor1 = lcm / xDen;
    int factor2 = lcm / yDen;
    return ((x.getNumer() * factor1) < (y.getNumer() * factor2));
}

//overloaded operator <<
ostream &operator<<(ostream &output, fraction &fractionRef)
{
    output << fractionRef.getNumer() << "/"
           << fractionRef.getDenom();
    return output;
}

void sort(fraction arr[], int size,
          function<bool(fraction, fraction)> OutOfOrder)
{
    bool Swaps;
    fraction temp;
    do
    {
        Swaps = false;
        for (int i = 0; i < size - 1; ++i)
            if (OutOfOrder(arr[i], arr[i + 1]))
            {
                temp = arr[i]; arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                Swaps = true;
            }
    } while (Swaps);
}

int GCD(int a, int b)
{
    while(true)
    {
        a = a % b;
        if (a == 0) return b;
        b = b % a;
        if (b == 0) return a;
    }
}

int LCM(int a,int b)
{
    return (a*b)/GCD(a,b);
}

// end implementation
