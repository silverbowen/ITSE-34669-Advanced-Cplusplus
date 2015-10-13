#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <string>
using namespace std;

class student
{
private:
    string _name;
    double _gpa;
public:
    student();
    student(string);
    student(string, double);
    string getname();
    double getgpa();
    void setname(string);
    void setgpa(double);
};

#endif // STUDENT_H_INCLUDED
