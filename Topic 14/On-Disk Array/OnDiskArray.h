/* Topic 14 = On Disk Array
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

// This implementation allows the user to write to disk as though the file
// were an array. It requires that the type of data and number of elements
// are both a fixed size.

#ifndef ONDISKARRAY_H
#define ONDISKARRAY_H

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

template<typename T>
class OnDiskArray
{
     public: //specified interface
     OnDiskArray(char *FileName, int MaxValues);
     ~OnDiskArray();
     void Set(int index, T value);
     T Get(int index);

     private:
     fstream odaFile; // fstream object
     T t; // a blank T t for reference
};

template<typename T>
OnDiskArray<T>::OnDiskArray(char *FileName, int MaxValues)
{
    odaFile.open(FileName, ios::out); // open and close file to ensure
    odaFile.close(); // that it exists (needed because this class is templated)

    odaFile.open(FileName, ios::in | ios::out | ios::binary); // reopen

    // for loop writes blank data, so elements are spaced correctly
    for (int i = 0; i < MaxValues; ++i)
        odaFile.write(reinterpret_cast<char*>(&t), sizeof(T));
}

template<typename T>
OnDiskArray<T>::~OnDiskArray()
{
    odaFile.close(); // destructor closes file
}

template<typename T>
void OnDiskArray<T>::Set(int index, T value)
{
    // set write pointer to correct index
    odaFile.seekp ((index - 1) * sizeof(T), ios::beg);
    // write value to location
    odaFile.write(reinterpret_cast<char*>(&value), sizeof(T));
}

template<typename T>
T OnDiskArray<T>::Get(int index)
{
    T t; // set read pointer to correct index
    odaFile.seekg ((index - 1) * sizeof(T), ios::beg);
    // read value from location into t, then return t
    odaFile.read(reinterpret_cast<char*>(&t), sizeof(T));
    return t;
}

#endif // ONDISKARRAY_H
