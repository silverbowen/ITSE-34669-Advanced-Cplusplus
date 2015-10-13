/* Topic 3 = Fraction class
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

#include "fraction.h"
#include <iostream>
using namespace std;
int main()
{
    cout <<
         "/* This program displays the code in main, //including comments\n"
         "   followed by the output/results. The code is indented for readability.\n"
         " */\n\n"
         "     fraction a;  // instantiate a w/ default values\n"
         "     id(\"a\");\n"
         "     a.print();   // show that a was instantiated w/ 0/1\n\n";

    /* This program displays the code in main, //including comments
       followed by the output/results. The code is indented for readability.
     */
    fraction a;  // instantiate a w/ default values
    id("a");
    a.print();   // show that a was instantiated w/ 0/1

    cout <<
         "\n     a.setNumer(1);\n"
         "     a.setDenom(2);  // change values w/ single setters\n"
         "     id(\"a\");\n"
         "     a.print();      // print a w/ new values 1/2\n\n";

    a.setNumer(1);
    a.setDenom(2);  // change values w/ single setters
    id("a");
    a.print();      // print a w/ new values 1/2

    cout <<
         "\n     a.setBoth(2,3);  // change values w/ setBoth\n"
         "     id(\"a\");\n"
         "     a.print();       // print a w/ new values 2/3\n\n";

    a.setBoth(2,3);  // change values w/ setBoth
    id("a");
    a.print();       // print a w/ new values 2/3

    cout <<
         "\n     fraction b;\n"
         "     b = a;           // demonstrate overridden assignment operator\n"
         "     a.setBoth(3,4);  // change values w/ setBoth\n"
         "     id(\"a\");\n"
         "     a.print();       // print a w/ new values 3/4\n"
         "     id(\"b\");\n"
         "     b.print();       // print b w/ old assigned values 2/3\n\n";

    fraction b;
    b = a;           // demonstrate overridden assignment operator
    a.setBoth(3,4);  // change values w/ setBoth
    id("a");
    a.print();       // print a w/ new values 3/4
    id("b");
    b.print();       // print b w/ old assigned values 2/3

    cout <<
         "\n     fraction c(b);   // demonstrate overridden copy constructor\n"
         "     b.setBoth(4,5);  // change values w/ setBoth\n"
         "     id(\"b\");\n"
         "     b.print();       // print a w/ new values 4/5\n"
         "     id(\"c\");\n"
         "     c.print();       // print a w/ old copied values 2/3\n\n";

    fraction c(b);   // demonstrate overridden copy constructor
    b.setBoth(4,5);  // change values w/ setBoth
    id("b");
    b.print();       // print a w/ new values 4/5
    id("c");
    c.print();       // print a w/ old copied values 2/3

    cout <<
         "\n     a.setBoth(10, 15);   // set a to 10/15 (reducible==true==1)\n"
         "     b.setBoth(10, 5);    // set b to 10/5 (reducible==true==1)\n"
         "     c.setBoth(10, 11);   // set c to 10/11 (reducible==false==0)\n"
         "     idR(\"a\");\n"
         "     cout << a.reducible() << endl;\n"
         "     idR(\"b\");\n"
         "     cout << b.reducible() << endl;\n"
         "     idR(\"c\");\n"
         "     cout << c.reducible() << endl;\n\n";

    a.setBoth(10, 15);   // set a to 10/15 (reducible==true==1)
    b.setBoth(10, 5);    // set b to 10/5 (reducible==true==1)
    c.setBoth(10, 11);   // set c to 10/11 (reducible==false==0)
    idR("a");
    cout << a.reducible() << endl;
    idR("b");
    cout << b.reducible() << endl;
    idR("c");
    cout << c.reducible() << endl;

    cout <<
         "\n     a.reduceMe();  // reduce a to 2/3\n"
         "     b.reduceMe();  // reduce b to 2/1\n"
         "     c.reduceMe();  // c doesn't reduce\n"
         "     idRM(\"a\");\n"
         "     a.print();\n"
         "     idRM(\"b\");\n"
         "     b.print();\n"
         "     idRM(\"c\");\n"
         "     c.print();\n\n";

    a.reduceMe();  // reduce a to 2/3
    b.reduceMe();  // reduce b to 2/1
    c.reduceMe();  // c doesn't reduce
    idRM("a");
    a.print();
    idRM("b");
    b.print();
    idRM("c");
    c.print();

    cout <<
         "\n     a.setBoth(4, 6);  // reset a to demonstrate reduce\n"
         "     b = a.reduce();   // set b to a.reduce()\n"
         "     id(\"a\");          // a is still 4/6\n"
         "     a.print();\n"
         "     id(\"b\");          // b is now 2/3\n"
         "     b.print();\n\n";

    a.setBoth(4, 6);  // reset a to demonstrate reduce
    b = a.reduce();   // set b to a.reduce()
    id("a");          // a is still 4/6
    a.print();
    id("b");          // b is now 2/3
    b.print();

    cout <<
         "\n     a.setBoth(5, 10); // reset a and b to demonstrate add\n"
         "     b.setBoth(6, 12); // 5/10 plus 6/12 == 60/60\n"
         "     c = add(a, b);\n"
         "     id(\"a\");\n"
         "     a.print();\n"
         "     id(\"b\");\n"
         "     b.print();\n"
         "     idA(\"a\", \"b\");\n"
         "     c.print();\n"
         "     id(\"c\");\n"
         "     c.print();\n\n";

    a.setBoth(5, 10); // reset a and b to demonstrate add
    b.setBoth(6, 12); // 5/10 plus 6/12 == 60/60
    c = add(a, b);
    id("a");
    a.print();
    id("b");
    b.print();
    idA("a", "b");
    c.print();
    id("c");
    c.print();

    cout <<
         "\n     c.setBoth(3, 4);  // reset c to > a and b to demonstrate lessThan\n"
         "     idLT(\"a\", \"b\");   // a and b are equal, so lessThan returns 0==false\n"
         "     cout << lessThan(a, b) << endl;\n"
         "     idLT(\"a\", \"c\");  // lessThan returns true==1\n"
         "     cout << lessThan(a, c) << endl;\n"
         "     idLT(\"c\", \"b\");  // lessThan returns false==0\n"
         "     cout << lessThan(c, b) << endl;\n\n";

    c.setBoth(3, 4);  // reset c to > a and b to demonstrate lessThan
    idLT("a", "b");   // a and b are equal, so lessThan returns 0==false
    cout << lessThan(a, b) << endl;
    idLT("a", "c");  // lessThan returns true==1
    cout << lessThan(a, c) << endl;
    idLT("c", "b");  // lessThan returns false==0
    cout << lessThan(c, b) << endl;

    cout <<
         "\n     {\n"
         "      fraction *x; // demonstrate explicit destructor\n"
         "      fraction y;  // and fun with pointers\n"
         "      x=&y;\n"
         "      id(\"x\");\n"
         "      x->print();  // x and y point to same object\n"
         "      id(\"y\");\n"
         "      y.print();\n\n";

    {
        fraction *x; // demonstrate explicit destructor
        fraction y;  // and fun with pointers
        x=&y;
        id("x");
        x->print();  // x and y point to same object
        id("y");
        y.print();

        cout <<
             "\n      x->setBoth(3, 4);  // setting x changes y\n"
             "      id(\"x\");\n"
             "      x->print();\n"
             "      id(\"y\");\n"
             "      y.print();\n\n";

        x->setBoth(3, 4);  // setting x changes y
        id("x");
        x->print();
        id("y");
        y.print();

        cout <<
             "\n      x->~fraction();          // call destructor (deletes x)\n"
             "      x = new fraction(5, 6);  // new x\n"
             "      id(\"x\");\n"
             "      x->print();\n"
             "      id(\"y\");                 // y has not changed\n"
             "      y.print();\n\n";

        x->~fraction();          // call destructor (deletes x)
        x = new fraction(5, 6);  // new x
        id("x");
        x->print();
        id("y");                 // y has not changed
        y.print();

        cout <<
             "\n      delete x;    // delete x directly\n"
             "      id(\"x\");\n"
             "      x->print();\n"
             "      id(\"y\");     // y has still not changed\n"
             "      y.print();   // leaving scope now\n"
             "     }\n\n";

        delete x;    // delete x directly
        id("x");
        x->print();
        id("y");     // y has still not changed
        y.print();   // leaving scope now
        cout << endl;
    }

// uncomment below along w/ constructor/assignment/destructor call
// cout statements to see extent/timing of calls
//cout << "Scope has been left. Leaving main...\n\n";

} // end main
