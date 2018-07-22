#pragma once
#include <iostream>
using namespace std;

template <typename T>
void printOutput(T* arrayA, size_t length)
{
    cout << " | ";
    for (int i = 0; i < length; i++)
    {
        cout << arrayA[i] << " | ";
    }
    cout << endl;
}

template <typename T>
T * insertionSort(T *input, size_t len) {
    int j;
    T temp;
    
    for (int i = 0; i < len; i++){
        j = i;
        
        while (j > 0 && input[j] < input[j-1]){
            temp = input[j];
            input[j] = input[j-1];
            input[j-1] = temp;
            j--;
        }
    }
    return input;
}

template <typename T>
void sortIt(T* arrayA, size_t length)
{
    T* sortArray = new T[length];
    for (int i = 0; i < length; i++)
    {
        sortArray[i] = arrayA[i];
    }
    
    insertionSort(sortArray, length);
    printOutput(sortArray, length);
    
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0) arrayA[i] = sortArray[length - 1 - (i/2)];
        else arrayA[i] = sortArray[(i/2)];
    }
    
    delete[] sortArray;
}

