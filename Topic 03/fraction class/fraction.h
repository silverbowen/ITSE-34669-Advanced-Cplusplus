/* Topic 3 = Fraction class
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class fraction
{
public:
    fraction();
    fraction(int num, int den);
    ~fraction();
    fraction(const fraction& other);
    fraction& operator=(const fraction& other);
    void print();
    bool reducible();
    void reduceMe();
    fraction reduce();
    int getNumer();
    int getDenom();
    void setNumer(int num);
    void setDenom(int den);
    void setBoth(int num, int den);


private:
    int numer, denom;
};

fraction add(fraction x, fraction y);
bool lessThan(fraction x, fraction y);
void id(string id);
void idR(string id);
void idRM(string id);
void idA(string x, string y);
void idLT(string x, string y);
int GCD(int a, int b);
int LCM(int a,int b);

#endif // end FRACTION_H
