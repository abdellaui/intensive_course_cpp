#include "sortable.h"

Sortable::Sortable()
{
	m_a = 1;
	m_b = 20;
};
Sortable::Sortable(const int& a,const int& b)
{
	if (a > 0)
		m_a = a;
	else
		m_a = (a)*(-1);
	if (b > 0)
		m_b = b;
	else
		m_b = (b)*(-1);
};
Sortable::~Sortable(){};


bool Sortable::operator< (const Sortable & other) const
{
	return (m_a * m_b < other.m_a * other.m_b);
};

void Sortable::operator= (const Sortable & other)
{
	m_b = other.m_b;
	m_a = other.m_a;
};

//Fuer Aufgabe 2
bool Sortable::operator== (const Sortable & other) const
{
    return (m_a == other.m_a && m_b == other.m_b);
}
