/* Topic 14 = On Disk Array
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

#include "OnDiskArray.h"
#include <string>
using namespace std;

int main()
{
    {   // int test
        typedef int Thingy;

        int value = 3;

        OnDiskArray<Thingy> Thingies("MyThingies.dat", value);

        Thingy t1, t2, t3;

        t1 = 1;
        t2 = 2;
        t3 = 3;

        Thingies.Set(1,t1);
        Thingies.Set(2,t2);
        Thingies.Set(3,t3);

        cout << "Here is t1: " << Thingies.Get(1) << endl;
        cout << "Here is t2: " << Thingies.Get(2) << endl;
        cout << "Here is t3: " << Thingies.Get(3) << "\n\n";
    }

    {   // float test
        typedef float Thingy;

        int value = 3;

        OnDiskArray<Thingy> Thingies("MyThingies.dat", value);

        Thingy t1, t2, t3;

        t1 = 1.111;
        t2 = 2.222;
        t3 = 3.333;

        Thingies.Set(3,t1);
        Thingies.Set(2,t2);
        Thingies.Set(1,t3);

        cout << "Here is t1: " << Thingies.Get(1) << endl;
        cout << "Here is t2: " << Thingies.Get(2) << endl;
        cout << "Here is t3: " << Thingies.Get(3) << "\n\n";
    }

    {   // char test
        typedef char Thingy;

        int value = 3;

        OnDiskArray<Thingy> Thingies("MyThingies.dat", value);

        Thingy t1, t2, t3;

        t1 = 'a';
        t2 = 'b';
        t3 = 'c';

        Thingies.Set(3,t1);
        Thingies.Set(1,t2);
        Thingies.Set(2,t3);

        t1 = Thingies.Get(3);
        t2 = Thingies.Get(1);
        t3 = Thingies.Get(2);

        cout << "Here is t1: " << t1 << endl;
        cout << "Here is t2: " << t2 << endl;
        cout << "Here is t3: " << t3 << "\n\n";
    }

    // char* test
    typedef char *Thingy;

    int value = 3;

    OnDiskArray<Thingy> Thingies("MyThingies.dat", value);

    Thingy t1 = "Beam me up, Scotty ",
           t2 = "-------------------",
           t3 = "No intelligent life";

    Thingies.Set(3,t1);
    Thingies.Set(1,t2);
    Thingies.Set(2,t3);

    t1 = Thingies.Get(3);
    t2 = Thingies.Get(1);
    t3 = Thingies.Get(2);

    cout << "Here is t1: " << t1 << endl;
    cout << "Here is t2: " << t2 << endl;
    cout << "Here is t3: " << t3 << "\n\n";

    return 0;
} // end main
