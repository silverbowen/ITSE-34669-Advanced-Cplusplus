#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// prototypes
void printVector(vector<int> &ref);
bool isBee(int n);
bool isNotBee(int n);

int main()
{
    // 1) declare vector, add grades (identical to sample)
    vector<int> scores{79, 100, 84, 63, 72, 98, 81, 87, 77, 89, 83};

    // 2) print out grades
    cout << "Vector scores:\n";
    printVector(scores);

    // 3) count number of bees (and print)
    vector<int> bees(count_if(scores.begin(), scores.end(), isBee));
    cout << "Number of bees: " << bees.size() << "\n";

    // 4) copy the bee scores to second vector bees
    copy_if(scores.begin(), scores.end(), bees.begin(), isBee);

    // 5) sort the first vector
    sort(scores.begin(), scores.end());

    // 6) print sorted vector
    cout << "\nSorted vector scores:\n";
    printVector(scores);

    // 7) remove non-bees from first vector
    scores.resize(
        remove_if(scores.begin(), scores.end(), isNotBee) - scores.begin() );

    // 8) sort the second vector
    sort(bees.begin(), bees.end());

    // 9) print both vectors
    cout << "Sorted vector scores w/ non-bees removed:\n";
    printVector(scores);

    cout << "Sorted vector bees:\n";
    printVector(bees);

    // 10) compare vectors and print determination
    cout << "Verdict: vector scores and vector bees are ";
    equal(scores.begin(), scores.end(), bees.begin())
        ? cout << "the same.\n" : cout << "different.\n";

} // end main

// prints a vector
void printVector(vector<int> &ref)
{
    cout << endl;
    for_each(ref.begin(), ref.end(), [] (int n) {cout << n << endl;});
    cout << endl;
}

bool isBee (int n)
{
   return (n >= 80 &&  n <= 89);
};

bool isNotBee(int n)
{
    return !isBee(n);
};
