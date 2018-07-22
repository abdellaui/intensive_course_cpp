#include <iostream>
#include "statistik.h"
#include "../01_aufgabe/sortingAlgo.h"
using namespace std;

int main()
{

    // DOUBLE
    
    
	cout << endl << "Double Test:" << endl << endl;

	double doubleArray[6] = {5.5, -5.3, 2.7, 6.9, -4.1, 8.2};
    size_t doubleLenght = (sizeof(doubleArray)/sizeof(doubleArray[0]));
	printOutput(doubleArray, (int)doubleLenght);
	
	Statistik<double> doubleStatistik;
	for (int i = 0; i < doubleLenght; i++)
	{
		doubleStatistik.nextValue(doubleArray[i]);
	}
    
    cout << endl;
	cout << "Maximum: " << doubleStatistik.getMaximum() << " Minimum: " << doubleStatistik.getMinimum();
	cout << " Average: " << doubleStatistik.getAverage() << " Variance: " << doubleStatistik.getVariance() << endl;

    
    // INTEGER
    
    
    cout << endl << "Integer Test:" << endl << endl;
    
	int integerArray[6] = { 5, -5, 2, 6, -4, 8};
    size_t integerLenght = (sizeof(integerArray)/sizeof(integerArray[0]));
    printOutput(integerArray, (int)integerLenght);
    
    Statistik<int> integerStatistik;
	for (int i = 0; i < integerLenght; i++)
	{
		integerStatistik.nextValue(integerArray[i]);
	}
    
	cout << endl;
	cout << "Maximum: " << integerStatistik.getMaximum() << " Minimum: " << integerStatistik.getMinimum();
	cout << " Average: " << integerStatistik.getAverage() << " Variance: " << integerStatistik.getVariance() << endl;

	return 0;
}
