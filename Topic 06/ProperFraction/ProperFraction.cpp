/* Topic 06 = ProperFraction
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

#include "ProperFraction.h"
#include <iostream>

using namespace std;

ProperFraction::ProperFraction() : fraction()
{
    convertProper();
}  // default constructor

ProperFraction::ProperFraction(int num, int den) : fraction(num, den)
{
    convertProper();
}  // overloaded conversion constructor

ProperFraction::~ProperFraction() {}

ProperFraction::ProperFraction(const ProperFraction& other)
{
    setThree(other.whole, other.numer, other.denom);
}   // copy constructor

ProperFraction& ProperFraction::operator=(const ProperFraction& other)
{
    if (this == &other) return *this; // handle self-assignment

    setThree(other.whole, other.numer, other.denom);
    return *this;
}

void ProperFraction::convertProper()
{
    while (getNumer() >= getDenom())
    {
        ++whole;
        fraction::setNumer(getNumer() - getDenom());
    };
}  // sets whole and numer

void ProperFraction::revertProper()
{
    while (whole > 0)
    {
        --whole;
        fraction::setNumer(getNumer() + getDenom());
    };
}  // unsets whole and numer

void ProperFraction::setWhole(int whl)
{
    whole = whl; // setWhole() only changes whole !!!
}

int ProperFraction::getWhole()
{
    return whole;
}

void ProperFraction::setNumer(int num)
{
    revertProper();
    fraction::setNumer(num); // changes numer & whole
    convertProper();
}

void ProperFraction::setDenom(int den)
{
    revertProper();
    fraction::setDenom(den); // changes denom and whole
    convertProper();
}

void ProperFraction::setBoth(int num, int den)
{
    revertProper();
    fraction::setBoth(num, den); // changes numer, denom, and whole
    convertProper();
}

void ProperFraction::setThree(int whl, int num, int den)
{
    setWhole(whl);               // changes whole only
    fraction::setBoth(num, den); // changes numer and denom only
    convertProper();
}

void ProperFraction::print() // prints a visual form of the proper fraction
{
    if (whole && getNumer())
    {
        cout << getWhole() << " & ";
        fraction::print();
    }

    else if (getNumer())
        fraction::print();

    else
        cout << getWhole() << endl;
}

bool ProperFraction::reducible()
{   // returns bool indicating value can/cannot be reduced
    return returnImproper(*this).fraction::reducible();
}

void ProperFraction::reduceMe()
{   // ensures that this instance is fully reduced
    revertProper();
    fraction::reduceMe();
    convertProper();
}

ProperFraction ProperFraction::reduce()
{ // returns a new fraction, fully-reduced version of original
    ProperFraction x = returnImproper(*this);
    x.fraction::reduce();
    x.convertProper();
    return x;
}

ProperFraction returnImproper(ProperFraction pf)
{ // nonmember function to return an improper copy of a fraction
    pf.revertProper();
    return pf;
}

ProperFraction add(ProperFraction x, ProperFraction y)
{   // non-member function to return a new proper fraction
    // containing the sum of two others;
    x.revertProper();
    y.revertProper();

    int xDen = x.getDenom();
    int yDen = y.getDenom();

    int lcm = LCM(xDen, yDen);          // it would be trivial to implement
    int factor1 = lcm / xDen;           // reduceMe here if desired.
    int factor2 = lcm / yDen;

    int num = (x.getNumer() * factor1) + (y.getNumer() * factor2);
    return ProperFraction(num, lcm);
}

bool lessThan(ProperFraction x, ProperFraction y)
{   // non-member function returning a bool indicating if x < y
    x.revertProper();
    y.revertProper();

    int xDen = x.getDenom();
    int yDen = y.getDenom();

    int lcm = LCM(xDen, yDen);           // same code as add, mostly
    int factor1 = lcm / xDen;
    int factor2 = lcm / yDen;

    return ((x.getNumer() * factor1) < (y.getNumer() * factor2));
}
