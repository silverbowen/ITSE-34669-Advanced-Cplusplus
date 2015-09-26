#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Name::ReverseUsingString()
{
    // lastChar holds the length of TheName
    const int lastChar = TheName.length();

    // space holds the position of the space between first and last names
    const int space = TheName.find(" ");

    // NameThe is assigned the reversed string via substrings and the
    // String class overridden + operator (concatenate)
    string NameThe = TheName.substr(space + 1, lastChar - space)
                     + ", " + TheName.substr(0, space);

    // return the reversed copy
    return NameThe;
}

void Name::ReverseUsingArray(char RevArray[])
{
    // lastChar will hold the length of TheName
    int lastChar = 0;

    // space will hold the position of the space between first and last names
    int space = 0;

    // convenience int that will hold lastChar - space - 1
    int lastLen = 0;


    // while loop increments lastChar until it hits '\0'
    while (TheName[lastChar])
    {
        ++lastChar;
    }

    // while loop increments space until it hits ' '
    while (TheName[space] != ' ')
    {
        ++space;
    }

    // set lastLen
    lastLen = lastChar - space - 1;

    // iterate through  RevArray and set it to last name
    for (int i = 0; i <= lastLen; i++)
    {
        RevArray[i] = TheName[i + space + 1];
    }

    // add comma, space
    RevArray[lastLen] = ',';
    RevArray[lastLen + 1] = ' ';

    // iterate through rest of RevArray and set it to first name
    for (int i = 0; i < space; i++)
    {
        RevArray[i + lastLen + 2] = TheName[i];
    }

    // add null terminator
    RevArray[lastChar + 1] = '\0';
}

void Name::ReverseUsingPtrs(char *RevPtr)
{
    // lastChar will hold the length of TheName
    int lastChar = 0;

    // space will hold the position of the space between first and last names
    int space = 0;

    // convenience int that will hold lastChar - space - 1
    int lastLen = 0;

    // name holds pointer to c-string copy of TheName
    const char *name = TheName.c_str();

    // while loop increments lastChar until it hits '\0'
    while (*(name + lastChar))
    {
        ++lastChar;
    }

    // while loop increments space until it hits ' '
    while (*(name + space) != ' ')
    {
        ++space;
    }

    // set lastLen
    lastLen = lastChar - space - 1;

    // iterate through  RevPtr and set it to last name
    for (int i = 0; i <= lastLen; i++)
    {
        *(RevPtr + i) = *(name + i + space + 1);
    }

    // add comma, space
    *(RevPtr + lastLen) = ',';
    *(RevPtr + lastLen + 1) = ' ';

    // iterate through rest of RevPtr and set it to first name
    for (int i = 0; i < space; i++)
    {
        *(RevPtr + i + lastLen + 2) = *(name + i);
    }

    // add null terminator
    *(RevPtr + lastChar + 1) = '\0';
}
