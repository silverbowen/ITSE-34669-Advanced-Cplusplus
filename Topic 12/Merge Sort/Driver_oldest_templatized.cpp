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
    typedef typename vector<T>::iterator Type;
    vector<T> returnVector;
    vector<T> leftVector;
    vector<T> rightVector;

    Type start = refVector.begin();
    Type finish = refVector.end();

    Type leftIndex;
    Type leftEnd;
    Type rightIndex;
    Type rightEnd;

    if (refVector.size() == 1)
    {
        returnVector.push_back(*start);
        return returnVector;
    }

    while (start < finish)
    {
        leftVector.push_back(*start);
        ++start;
        if (start < finish)
        {
           rightVector.push_back(*start);
           ++start;
        }
    }

    leftVector = mergeSort(leftVector);
    rightVector = mergeSort(rightVector);

    leftIndex = leftVector.begin();
    leftEnd = leftVector.end();
    rightIndex = rightVector.begin();
    rightEnd = rightVector.end();

    while (leftIndex < leftEnd && rightIndex < rightEnd)
    {
        if (*leftIndex <= *rightIndex)
        {
             returnVector.push_back(*leftIndex);
             ++leftIndex;
        }

        else
        {
             returnVector.push_back(*rightIndex);
             ++rightIndex;
        }
    }

    if (leftIndex == leftEnd)
    {
        while (rightIndex < rightEnd)
        {
             returnVector.push_back(*rightIndex);
             ++rightIndex;
        }
    }
    else
    {
        while (leftIndex < leftEnd)
        {
            returnVector.push_back(*leftIndex);
            ++leftIndex;
        }
    }

    return returnVector;
}
