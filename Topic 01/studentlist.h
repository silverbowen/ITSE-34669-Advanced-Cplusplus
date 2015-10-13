#ifndef STUDENTLIST_INCLUDED
#define STUDENTLIST_INCLUDED
#include "student.h"
#include <string>
#include <vector>
using namespace std;

class studentlist
{
private:
    vector<student> _SL;
public:
    studentlist();
    int count();
    int addnew(student);
    int addnew(string, double);
    student operator[] (int);
};

#endif // STUDENTLIST_INCLUDED
