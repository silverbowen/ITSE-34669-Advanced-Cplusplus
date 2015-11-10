/* Topic 08 = Fraction Sort
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

#include "fraction.h"
using namespace std;

// predicate function prototype
bool OutOfOrder1(fraction f1, fraction f2);

// functor definition
class OutOfOrder2
{
    string howToSort = "low to high";

    public:
        OutOfOrder2(string hts);
        bool operator() (fraction f1, fraction f2);
};

// print function prototype
void printArray(fraction arr[], int size);

int main()
{
    int size = 7;  // set size of arrays

    // make an array of disordered fractions
    fraction arr1[] = {fraction(1, 3), fraction(2, 4),
                       fraction(4, 6), fraction(3, 5),
                       fraction(7, 9), fraction(5, 7),
                       fraction(6, 8)};

    // make two more arrays
    fraction arr2[size], arr3[size];

    // copy 1st array twice
    for (int i = 0; i < size; i++)
        arr2[i] = arr3[i] = arr1[i]; // uses fraction copy constructor

    // make an OutOfOrder2 object
    OutOfOrder2 O4("low to high");

    sort(arr1, size, OutOfOrder1); // call w/ function pointer
    printArray(arr1, size);

    sort(arr2, size, O4); // call with functor
    printArray(arr2, size);

    sort(arr3, size, [] (fraction f1, fraction f2)
                        {return lessThan(f2, f1);}); // call with lambda
    printArray(arr3, size);
} // end main

// predicate function implementation - returns a bool indicating if
// the second fraction is less than the first one.
bool OutOfOrder1(fraction f1, fraction f2) {return lessThan(f2, f1);}

// functor implementations - provides same functionality as previous
// function, but also includes ability to sort high to low.
OutOfOrder2::OutOfOrder2(string hts) : howToSort(hts) {}; // constructor

bool OutOfOrder2::operator() (fraction f1, fraction f2) // operator()
{
    if (howToSort == "low to high")
        return lessThan(f2, f1);
    else  // if howToSort != "low to high", sort high to low.
        return lessThan(f1, f2);
};

// print function implementation
void printArray(fraction arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << endl;   // print sorted array
    cout << endl;
}
