#include "studentlist.h"
using namespace std;

studentlist::studentlist() {}
int studentlist::count() { return _SL.size(); }
int studentlist::addnew(student s) { _SL.push_back(s);  return _SL.size(); }
int studentlist::addnew(string name, double gpa) { _SL.push_back(student(name,gpa));  return _SL.size(); }
student studentlist::operator[] (int index) { return _SL[index]; }
