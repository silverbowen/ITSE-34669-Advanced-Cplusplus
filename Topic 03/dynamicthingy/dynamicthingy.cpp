#include <iostream>
#include <string>
using namespace std;

class dynamicthingy
{
public:
    string *name;

    void setname(char *n)
    {
        string *newname = new string(n);
        name = newname;
    }

    string getname()
    {
        return *name;
    }

    void initialize()
    {
        name = NULL;
    }

    dynamicthingy()
    {
        initialize();
    }

    dynamicthingy(char *n)
    {
        initialize();
        string *newname = new string(n);
        if (name != NULL) delete name;
        name = newname;
    }

    dynamicthingy(const dynamicthingy &other) // added copy constructor
    {
        name = other.name;
    }
};

int main()
{
    dynamicthingy dt1("Ster"),dt2(dt1);

    cout << dt1.getname() << dt2.getname() << endl;

    dt1.setname("Rick");

    cout << dt1.getname() << dt2.getname() << endl;
}

