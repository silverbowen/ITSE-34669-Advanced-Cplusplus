/* Topic 06 = ProperFraction
   for ITSE 34669 advanced C++
   William Bowen w1702335

   Unfortunately, inheritance didn't really help this class out very much.
   I ended up having to override almost everything from the base class, due to
   the requirement that this class contain a whole number part. The helper
   functions from the base class also had to be overridden. It would have been
   fairly easy to have just modified the derived class to only print as a proper
   fraction, I suppose, but that didn't seem to be your requirement.

   the overridden setNumer and setDenom functions operate on the assumption
   that the user should be able to work with proper fractions as if they
   were regular fractions. So changing the numerator or denominator affects
   whole as well, ie changing numerator for 1 & 1/2 actually changes numerator
   for 3/2. */

#ifndef PROPERFRACTION_H
#define PROPERFRACTION_H

#include "fraction.h"

using namespace std;

class ProperFraction : public fraction
{
public:
    ProperFraction();
    ProperFraction(int num, int den);
    ~ProperFraction();
    ProperFraction(const ProperFraction& other);
    ProperFraction& operator=(const ProperFraction& other);
    void convertProper();
    void revertProper();
    void setWhole(int whl);
    int getWhole();
    void setNumer(int num);
    void setDenom(int den);
    void setBoth(int num, int den);
    void setThree(int whl, int num, int den);
    void print();
    bool reducible();
    void reduceMe();
    ProperFraction reduce();

private:
    int whole = 0;
};

ProperFraction returnImproper(ProperFraction pf);
ProperFraction add(ProperFraction x, ProperFraction y);
bool lessThan(ProperFraction x, ProperFraction y);

#endif // PROPERFRACTION_H
