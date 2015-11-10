/* Topic 06 = ProperFraction
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

#include "ProperFraction.h"
#include <iostream>

using namespace std;

int main()
{
    ProperFraction a;  // instantiate a w/ default values 0/1
    id("a");
    a.print();   // prints 0/1 as proper fraction 0
    cout << endl;

    a.setNumer(2);
    a.setDenom(1);  // change values w/ single setters
    id("a");
    a.print();      // print 2/1 as proper fraction 2
    cout << endl;

    a.setBoth(3,2);  // change values w/ setBoth
    id("a");
    a.print();       // print 3/2 as proper fraction 1 & 1/2
    cout << endl;

    ProperFraction b;
    b = a;           // demonstrate overridden assignment operator
    a.setBoth(4,3);  // change values w/ setBoth
    id("a");
    a.print();       // prints a 4/3 as proper fraction 1 & 1/3
    id("b");
    b.print();       // prints b 3/2  as proper fraction  1 & 1/2
    cout << endl;

    ProperFraction c(b);   // demonstrate overridden copy constructor
    b.setBoth(5,4);  // change values w/ setBoth
    id("b");
    b.print();       // prints b 5/4 as proper fraction  1 & 1/4
    id("c");
    c.print();       // prints c 3/2 as proper fraction 1 & 1/2
    cout << endl;

    a.setBoth(15, 15);   // set a to 15/15 (reducible==true==1)
    b.setBoth(10, 5);    // set b to 10/5 (reducible==true==1)
    c.setBoth(10, 11);   // set c to 10/11 (reducible==false==0)
    idR("a");
    cout << a.reducible() << endl; //  as proper fraction 1
    idR("b");
    cout << b.reducible() << endl; // as proper fraction 2
    idR("c");
    cout << c.reducible() << endl; //  as proper fraction 10/11
    cout << endl;

    a.reduceMe();  // reduce a to 1/1 = 1
    b.reduceMe();  // reduce b to 2/1 = 2
    c.reduceMe();  // c doesn't reduce = 10/11
    idRM("a");
    a.print(); //  as proper fraction  1
    idRM("b");
    b.print(); //  as proper fraction 2
    idRM("c");
    c.print(); //  as proper fraction  10/11
    cout << endl;

    a.setBoth(6, 4);  // reset a to demonstrate reduce
    b = a.reduce();   // set b to a.reduce()
    id("a");          // a is still proper fraction  1 & 2/4 (not reduced)
    a.print();
    id("b");          // b is now proper fraction  1 & 2/4 (not reduced)
    b.print();
    cout << endl;

    a.setBoth(5, 10); // reset a and b to demonstrate add
    b.setBoth(6, 12); // 5/10 plus 6/12 == 60/60
    c = add(a, b);
    id("a");
    a.print(); //  as proper fraction 5/10
    id("b");
    b.print(); //  as proper fraction 6/12
    idA("a", "b");
    c.print(); //  as proper fraction 1
    id("c");
    c.print(); //  as proper fraction 1
    cout << endl;

    c.setBoth(3, 4);  // reset c to > a and b to demonstrate lessThan
    idLT("a", "b");   // a and b are equal, so lessThan returns 0==false
    cout << lessThan(a, b) << endl;
    idLT("a", "c");  // lessThan returns true==1
    cout << lessThan(a, c) << endl;
    idLT("c", "b");  // lessThan returns false==0
    cout << lessThan(c, b) << endl;
    cout << endl;

    {
        ProperFraction *x; // demonstrate explicit destructor
        ProperFraction y;  // and fun with pointers
        x=&y;
        id("x");
        x->print();  // x and y point to same object
        id("y");
        y.print();
        cout << endl;

        x->setBoth(3, 4);  // setting x changes y
        id("x");
        x->print();
        id("y");
        y.print();
        cout << endl;

        x->~ProperFraction();          // call destructor (deletes x)
        x = new ProperFraction(5, 6);  // new x
        id("x");
        x->print();
        id("y");                 // y has not changed
        y.print();
        cout << endl;

        delete x;    // delete x directly
        id("x");
        x->print();
        id("y");     // y has still not changed
        y.print();   // leaving scope now
        cout << endl;
    }

} // end main
