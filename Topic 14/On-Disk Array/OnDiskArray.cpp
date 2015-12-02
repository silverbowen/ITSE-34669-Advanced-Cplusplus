#include "OnDiskArray.h"
using namespace std;

template<typename T>
OnDiskArray<T>::OnDiskArray(char *FileName, int MaxVals)
{
    odaFile = (&FileName, ios::in | ios::out | ios::binary);
    MaxVals > 0 ? MaxValues = MaxVals : MaxValues = 0;
}

template<typename T>
OnDiskArray<T>::~OnDiskArray()
{
    odaFile.close();
}

template<typename T>
void OnDiskArray<T>::Set(int index, T value)
{

}

template<typename T>
T OnDiskArray<T>::Get(int index)
{

}
