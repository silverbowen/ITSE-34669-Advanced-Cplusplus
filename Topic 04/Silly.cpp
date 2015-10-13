#include <iostream>
using namespace std;

class Silly
{
public:
    int value;
    Silly()
    {
        value=0;
    }
    Silly(int value)
    {
        this->value=value;
    }

    Silly& operator++()
    {
        value += 1;
        return *this;
    }

    Silly operator++(int)
    {
        Silly temp = *this;
        value += 1;
        return temp;
    }
};

Silly operator+(const Silly& val1, const Silly& val2)
{
    return Silly(val1.value + val2.value);
};

ostream& operator<<(ostream& out, const Silly& value)
{
    out << value.value;
    return out;
};

int main()
{
    int ia=1, ib=3;
    Silly sa(1), sb(3);

    cout << "before: ia, ib = " << ia << ", " << ib;
    cout << "     ia + ++ib = " << (ia + ++ib);
    cout << "     after: ia, ib = " << ia << ", " << ib << endl;
    cout << "before: sa, sb = " << sa << ", " << sb;
    cout << "     sa + ++sb = " << (sa + ++sb);
    cout << "     after: sa, sb = " << sa << ", " << sb << endl;
    cout << endl;

    cout << "before: ia, ib = " << ia << ", " << ib;
    cout << "     ia++ + ib = " << (ia ++ +ib);
    cout << "     after: ia, ib = " << ia << ", " << ib << endl;
    cout << "before: sa, sb = " << sa << ", " << sb;
    cout << "     sa++ + sb = " << (sa ++ +sb);
    cout << "     after: sa, sb = " << sa << ", " << sb << endl;
    cout << endl;

    return 0;
}
