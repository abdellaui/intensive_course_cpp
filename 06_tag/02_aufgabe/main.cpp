#include <iostream>
#include <string>
#include <ostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "termin.h"
#include "terminmanager.h"
using namespace std;
int main()
{

	bool keepRunning = true;
	std::multimap<time_t, Termin *> termins;
    // pointer unnötig
    
	Termin *newT = Termin::createInstance("01.02.2017 00:00", "02.02.2017 00:00", "last year");
	termins.insert(std::pair<time_t, Termin *>(std::chrono::system_clock::to_time_t(newT->getStart()), newT));
	newT = Termin::createInstance("01.05.2017 00:00", "02.05.2017 00:00", "2last year2");
	termins.insert(std::pair<time_t, Termin *>(std::chrono::system_clock::to_time_t(newT->getStart()), newT));

	newT = Termin::createInstance("01.02.2018 00:00", "02.02.2018 00:00", "this year");
	termins.insert(std::pair<time_t, Termin *>(std::chrono::system_clock::to_time_t(newT->getStart()), newT));
	newT = Termin::createInstance("01.05.2018 00:00", "02.05.2018 00:00", "2this year2");
	termins.insert(std::pair<time_t, Termin *>(std::chrono::system_clock::to_time_t(newT->getStart()), newT));

	newT = Termin::createInstance("01.02.2019 00:00", "02.02.2019 00:00", "next year");
	termins.insert(std::pair<time_t, Termin *>(std::chrono::system_clock::to_time_t(newT->getStart()), newT));
	newT = Termin::createInstance("01.05.2019 00:00", "02.05.2019 00:00", "2next year2");
	termins.insert(std::pair<time_t, Termin *>(std::chrono::system_clock::to_time_t(newT->getStart()), newT));

	TerminManager tManager(termins);

	cout << endl
		 << "##############################################" << endl
		 << endl;
	cout << "Options:" << endl
		 << endl;
	cout << "'c' (create) Termin erstellen." << endl;
	cout << "'d' (delete) Termin loeschen." << endl;
	cout << "'s' (show) alle Termine anzeigen." << endl;
	cout << "'p' (past) alle vergangenen Termine anzeigen." << endl;
	cout << "'f' (future) alle zukuenftigen Termine anzeigen." << endl;
	cout << "'o' (on date) alle Termine an einem Tag anzeigen." << endl;
	cout << "'i' (interval) alle Termine in einem Zeitraum anzeigen." << endl;
	cout << "'q' (quit) Programm beenden." << endl
		 << endl;
	while (keepRunning)
	{
		cout << endl;
		cout << "------------------------------";
		cout << endl;
		cout << "c-reate, d-elete, s-how, p-ast, f-uture, o-nday, i-nterval, q-uit" << endl;

		char input;

		cin >> input;
		cin.ignore();

		cout << endl;
		cout << "------------------------------";
		cout << endl;
		cout << endl;
		switch (input)
		{
		case 'c':
			// Neuer Termin
			tManager.createTermin();
			break;
		case 'd':
			tManager.deleteTermin();
			break;
		case 's':
			tManager.printAllTermine();
			break;
		case 'p':
			tManager.printPastTermine();
			break;
		case 'f':
			tManager.printFutureTermine();
			break;
		case 'o':
			// Termine an einem Tag
			tManager.printDayTermine();
			break;
		case 'i':
			// Termine in einem Zeitraum
			tManager.printRangeTermine();
			break;
		case 'q':
			cout << "bye bye..." << endl;
			keepRunning = false;
			break;
		default:
			cout << endl
				 << "Ein Fehler ist aufgetreten. Eingabe ungueltig!" << endl;
			break;
		}
	}

	for (const auto &it : termins)
	{
		delete it.second;
	}

	return 0;
}
