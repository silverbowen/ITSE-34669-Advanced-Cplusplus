//#include "stdafx.h"

#include <iostream>
#include <vector>
#include "prime.h"

using namespace std;

int main()
{
    int start,end;
    cout << "Welcome to Prof. King's prime number finder thingy\n\n";
    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the   end of the range: ";
    cin >> end;

    vector<int> Primes = FindPrimes(start,end);
    cout << "\nThe primes between " << start << " and " << end << " (inclusive) are: \n\n";

    for (auto ThisOne : Primes)
        cout << ThisOne << endl;

    cout << "\n\n\n";
    // system("pause");
    cin.get();  //using instead of system("pause")

    return 0;
}
