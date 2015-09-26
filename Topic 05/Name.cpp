#include <iostream>
#include <string>
using namespace std;

class Name
{
public:
    string TheName;

    Name()
    {
        TheName="";
    }

    Name(string name)
    {
        TheName=name;
    }

    string ReverseUsingString();
    void ReverseUsingArray(char Reversed[]);
    void ReverseUsingPtrs(char *Reversed);

    void operator =(char *name)
    {
        TheName=name;
    }
};

#include "NameClassImplementation.h" // You supply this file!

int main()
{
    Name Names[5];
    Names[0] = "Ben Dover";
    Names[1] = "Chuck Roast";
    Names[2] = "Jim Naysium";
    Names[3] = "Ella Quint";
    Names[4] = "Justin Case";

    char reversedname1[100], reversedname2[100];

    for (int i=0; i<5; ++i)
    {
        Names[i].ReverseUsingArray(reversedname1);

        Names[i].ReverseUsingPtrs(reversedname2);

        cout << "Original Name         : " << Names[i].TheName << endl;
        cout << "  reversed with arrays: -->" << reversedname1 << "<--\n";
        cout << "  reversed with ptrs  : -->" << reversedname2 << "<--\n";
        cout << "  reversed with string: -->"
             << Names[i].ReverseUsingString() << "<--\n\n";
    }

    //system("pause");   // commented out so this will run on Linux
    cin.get();  // using instead of system("pause")

    return 0;
}
