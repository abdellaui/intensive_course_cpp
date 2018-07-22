#include <iostream>
#include "fallendefaktorielle.h"
using namespace std;

int main()
{
	const int a = 5;
	const int b = 3;
	cout << "Die fallende Faktorielle von " << a << "," << b << " ist: " << fallendeFaktorielle<a, b>::val << endl;
	cout << "Die fallende Faktorielle von " << a << "," << b << " ist: " << fallendeFaktorielleKurz<a, b>::val << endl;
    
}
