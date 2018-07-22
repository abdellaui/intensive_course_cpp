#include <iostream>
#include <string>
#include "sortable.h"
#include "sortingAlgo.h"

using namespace std;

template <typename T>
int binarySearch(T* arrayA, int length, const T & subject);

int main()
{
	cout << "Sort array:" << endl;
	
	cout << endl << "***** Double *****" << endl << endl;
	
	double* doubleArray = new double[5];
    size_t doubleLenght = 5;

	doubleArray[0] = 0.8;
	doubleArray[1] = 13.8;
	doubleArray[2] = 7.1;
	doubleArray[3] = 2.3;
	doubleArray[4] = 0.3;
    
	printOutput(doubleArray, doubleLenght);
	cout << endl;
	insertionSort(doubleArray, doubleLenght);
	printOutput(doubleArray, doubleLenght);
	cout << endl;

	cout << "Find '13.8': " << binarySearch(doubleArray, doubleLenght, 13.8) << endl;
	cout << "Find '-2': " << binarySearch(doubleArray, doubleLenght, -2.0) << endl;
	delete[] doubleArray;

	cout << endl << "***** Integer *****" << endl << endl;
	int integerArray[20] = { 19, 11, 6, 3, 8, 1, 2, 4, 7, 14, 13, 15, 18, 17, 16, 5, 12, 10, 9, 0 };
    size_t integerLenght = 20;

	printOutput(integerArray, integerLenght);
	cout << endl;
	insertionSort(integerArray, 20);
	printOutput(integerArray, 20);

	cout << endl;

	cout << "Find '7': " << binarySearch(integerArray, integerLenght, 7) << endl;
	cout << "Find '3': " << binarySearch(integerArray, integerLenght, 3) << endl;

	cout << endl << "***** Sortable *****" << endl << endl;
	Sortable* sortableArray = new Sortable[6];
    size_t sortableLenght = 6;
	sortableArray[0] = Sortable(3, 7);
	sortableArray[1] = Sortable(5, 8);
	sortableArray[2] = Sortable(3, 1);
	sortableArray[3] = Sortable(7, 2);
	sortableArray[4] = Sortable(1, 8);
	sortableArray[5] = Sortable(3, 4);

	printOutput(sortableArray, sortableLenght);
	cout << endl;
	insertionSort(sortableArray, 6);
	printOutput(sortableArray, 6);

	cout << endl;

	cout << "Find '(3, 7)': " << binarySearch(sortableArray, sortableLenght, Sortable(3,7)) << endl;

	delete[] sortableArray;

    return 0;
}

template <typename T>
int binarySearch(T* arrayA, int length, const T & subject)
{
	int left_border = 0;
	int right_border = length - 1;
	int position = 0;
	
    while (left_border <= right_border)
	{
		position = left_border + ((right_border - left_border) / 2);	// Get the new midpoint of our area
		
		if (arrayA[position] == subject) return position;				// Have we just found our subject?

		else if (subject < arrayA[position]) right_border = position - 1;	// => Our element is bigger

		else left_border = position + 1;									// => Our element is smaller
	}
	
	return -1;																// not found...
}
