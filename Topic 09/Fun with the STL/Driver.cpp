#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

int main()
{
    // here's all the stuffs we will be filling
    vector <string> names;
    vector <int> scores;
    unordered_map <string, int> valuesMap;
    list <string> namesList;
    stack <string> namesStack;

    // 1) seed initial pair vector Values
    pair<string, int> Values[] =  //seed starting array of pairs
    {
        { "Stewie", 100 }, { "Brian", 90 }, { "Meg", 66 },
        { "Lois", 89 }, { "Chris", 17 }, { "Peter", 21 },
        { "Marge", 77 }, { "Bart", 62 }, { "Lisa", 99 },
        { "Maggie", 3 }
    };

    // 2) add Values values to vectors names and scores
    for (int i = 0; i < (end(Values) - begin(Values)); ++i)
    {
        names.push_back(Values[i].first);
        scores.push_back(Values[i].second);
    };

    // 3) print names and scores values, then add to valuesMap
    for (size_t i = 0; i < names.size() || i < scores.size(); ++i)
    {
        cout << names[i] << " got " << scores[i] << endl;
        valuesMap.emplace (names[i], scores[i]);
    };

    // 4) add valuesMap values to namesList
    for (auto& iter : valuesMap)
        namesList.push_back(iter.first);

    // 5) sort namesList
    namesList.sort();

    // 6) add namesList values to namesStack
    for (auto iter : namesList)
        namesStack.push(iter);

    cout << endl; // spacer

    // 7) while namesStack isn't empty, print namesStack values LIFO,
    //    then pop them off
    while (!namesStack.empty())
    {
        cout << namesStack.top() << endl;
        namesStack.pop();
    };

} // end main
