#include <iostream>
#include <string>
#include "sortable.h"
#include "sortingAlgo.h"

using namespace std;

int main()
{
	cout << "Sort array:" << endl;

	int integerArray[20] = { 19, 11, 6, 3, 8, 1, 2, 4, 7, 14, 13, 15, 18, 17, 16, 5, 12, 10, 9, 0 };
	double* doubleArray = new double[5];

	doubleArray[0] = 0.8;
	doubleArray[1] = 13.8;
	doubleArray[2] = 7.1;
	doubleArray[3] = 2.3;
	doubleArray[4] = 0.3;

	printOutput(doubleArray, 5);
	cout << endl;
	sortIt(doubleArray, 5);
	printOutput(doubleArray, 5);
	cout << endl;
	cout << endl;

	printOutput(integerArray, 20);
	cout << endl;
	sortIt(integerArray, 20);
	printOutput(integerArray, 20);
	cout << endl;
	cout << endl;

	delete[] doubleArray;

    Sortable* sortableArray = new Sortable[6];

    sortableArray[0] = Sortable(3, 7);
    sortableArray[1] = Sortable(5, 8);
    sortableArray[2] = Sortable(3, 1);
    sortableArray[3] = Sortable(7, 2);
    sortableArray[4] = Sortable(1, 8);
    sortableArray[5] = Sortable(3, 4);

    printOutput(sortableArray, 6);
    cout << endl;
    sortIt(sortableArray, 6);
    printOutput(sortableArray, 6);

    delete[] sortableArray;

	return 0;
}
