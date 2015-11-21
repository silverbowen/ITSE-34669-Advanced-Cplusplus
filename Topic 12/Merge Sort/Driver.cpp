/* William Bowen - ITSE 34699 - Topic 12
   Merge Sort implementation using vectors.
   Templatized, no return type (merge in place).
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
void mergeSort(vector<T> &refVector);

int main ()
{   // make some vectors to sort
    vector<int> intVector {56, 7, 99, 12, 34, 15, 42, 42, 78, 51};
    vector<char> charVector {'t', 'h', 'e', 'q', 'u', 'i', 'c', 'k',
                             'b', 'r', 'o', 'w', 'n', 'f', 'o', 'x'};
    vector<string> stringVector {"jumped", "over", "the", "lazy", "dog"};

    // display the unsorted vectors
    cout << "Before:\n\n";

    printVector(intVector);
    printVector(charVector);
    printVector(stringVector);

    // call mergeSort to sort the vectors
    mergeSort(intVector);
    mergeSort(charVector);
    mergeSort(stringVector);

    // display the sorted vectors
    cout << "After:\n\n";

    printVector(intVector);
    printVector(charVector);
    printVector(stringVector);

    return 0;
}

// templatized vector print function
template <typename T>
void printVector(vector<T> const &vectorRef)
{
    for (auto i : vectorRef)
        cout << i << " ";
    cout << "\n\n";
}

// templatized recursive vector merge sort function
template <typename T>
void mergeSort(vector<T> &refVector)
{   // make 2 new vectors
    vector<T> leftVector;
    vector<T> rightVector;

    // fill new vectors with contents of refVector no attempt is made
    // to maintain any order here,  since these will be sorted later,
    // but only if refVector has at least 2 members
    if (refVector.size() > 1)  // the setup
    {   // while refVector has at least one member
        while (refVector.size() > 0)
        {   // transfer the last member of refVector to rightVector
            leftVector.push_back(refVector.back());
            refVector.pop_back();
            // if refVector has at least one member
            if (refVector.size() > 0)
            {   // transfer the last member of refVector to rightVector
                rightVector.push_back(refVector.back());
                refVector.pop_back();
            }
        } // end while -- setup is over

        // recursively call mergeSort on both newly filled vectors
        mergeSort(leftVector);
        mergeSort(rightVector);
        // recursion is over

        // sorting and merging happens here
        // while both leftVector and rightVector have members
        while (leftVector.size() > 0 && rightVector.size() > 0)
        {   // transfer the smaller of the two values to refVector
            if (leftVector.front() <= rightVector.front())
            {   // transfer then erase the first member of leftVector
                refVector.push_back(leftVector.front());
                leftVector.erase(leftVector.begin());
            }// end if

            else
            {   // transfer then erase the first member of rightVector
                refVector.push_back(rightVector.front());
                rightVector.erase(rightVector.begin());
            } // end else
        } // end while

        // only one of the following two while loops while ever activate
        // if leftVector still has members, transfer then erase them
        while (leftVector.size() > 0)
        {
            refVector.push_back(leftVector.front());
            leftVector.erase(leftVector.begin());
        } // end while

        // if rightVector still has members, transfer then erase them
        while (rightVector.size() > 0)
        {
            refVector.push_back(rightVector.front());
            rightVector.erase(rightVector.begin());
        } // end while -- sorting and merging is over
    } // end if
} // end main
