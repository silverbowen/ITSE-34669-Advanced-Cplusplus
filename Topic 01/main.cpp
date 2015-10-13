//#include "stdafx.h"

#include <iostream>
#include "studentlist.h"
using namespace std;

int main()
{
    studentlist SL;

    cout << "There are currently " << SL.count() << " students.\n";

    student Maggie, Bart("Bart"), Lisa("Lisa",4.0);

    cout << "There are currently " << SL.addnew(Maggie) << " students.\n";
    cout << "There are currently " << SL.addnew(Bart) << " students.\n";
    cout << "There are currently " << SL.addnew(Lisa) << " students.\n";
    cout << "There are currently " << SL.addnew("Homer",1.5) << " students.\n";

    cout << "The middle student is " << SL[2].getname() << endl;

    cout << "\n\n\n";
    //system("pause");   //commented out so this will run on Linux
    cin.get();  //using instead of system("pause")
    return 0;
}

