#include "student.h"
using namespace std;

student::student() { setname("");  setgpa(0.0); }
student::student(string name) { setname(name);  setgpa(0.0); }
student::student(string name,double gpa) { setname(name);  setgpa(gpa); }
string student::getname() { return _name; }
double student::getgpa() { return _gpa; }
void student::setname(string name) { _name=name; }
void student::setgpa(double gpa) { _gpa=gpa; }
