#pragma once
#include <iostream>

class Sortable
{
public:
	Sortable();
	Sortable(const int& a, const int& b);
	~Sortable();

	friend std::ostream& operator<< (std::ostream &os, Sortable &t) {
		os << "A = " << t.m_a * t.m_b;
		return os;
	};

	bool operator< (const Sortable & other) const;
	void operator= (const Sortable & other);
    //Fuer Aufgabe 2
    bool operator== (const Sortable & other) const;

private:
	int m_a;
	int m_b;
};
