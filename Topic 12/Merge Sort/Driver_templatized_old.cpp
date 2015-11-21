/* William Bowen - ITSE 34699 - Topic 12
   Merge Sort implementation using vectors.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// printVector just display a vector
template <typename T>
void printVector(vector<T> const &vectorRef);

// mergeSort merge sorts a vector
template <typename T>
vector<T> mergeSort(vector<T> &refVector);

int main ()
{
    vector<int> intVector {56, 7, 99, 12, 34, 15, 42, 42, 78, 51};
    vector<char> charVector {'t', 'h', 'e', 'q', 'u', 'i', 'c', 'k',
                             'b', 'r', 'o', 'w', 'n', 'f', 'o', 'x'};
    vector<string> stringVector {"jumped", "over", "the", "lazy", "dog"};

    cout << "Before:\n\n";

    printVector(intVector);
    printVector(charVector);
    printVector(stringVector);

    intVector = mergeSort(intVector);
    charVector = mergeSort(charVector);
    stringVector = mergeSort(stringVector);

    cout << "After:\n\n";

    printVector(intVector);
    printVector(charVector);
    printVector(stringVector);

    return 0;
}

template <typename T>
void printVector(vector<T> const &vectorRef)
{
    for (auto i : vectorRef)
        cout << i << " ";
    cout << "\n\n";
}

template <typename T>
vector<T> mergeSort(vector<T> &refVector)
{
    vector<T> returnVector;
    vector<T> leftVector;
    vector<T> rightVector;

    if (refVector.size() == 1)
    {
        returnVector.push_back(refVector.back());
        return returnVector;
    }

    while (refVector.size() > 0)
    {
        leftVector.push_back(refVector.back());
        refVector.pop_back();

        if (refVector.size() > 0)
        {
           rightVector.push_back(refVector.back());
           refVector.pop_back();
        }
    }

    leftVector = mergeSort(leftVector);
    rightVector = mergeSort(rightVector);

    while (leftVector.size() > 0 && rightVector.size() > 0)
    {
        if (leftVector.front() <= rightVector.front())
        {
             returnVector.push_back(leftVector.front());
             leftVector.erase(leftVector.begin());
        }

        else
        {
             returnVector.push_back(rightVector.front());
             rightVector.erase(rightVector.begin());
        }
    }

    while (leftVector.size() > 0)
    {
        returnVector.push_back(leftVector.front());
        leftVector.erase(leftVector.begin());
    }

    while (rightVector.size() > 0)
    {
        returnVector.push_back(rightVector.front());
        rightVector.erase(rightVector.begin());
    }

    return returnVector;
}
