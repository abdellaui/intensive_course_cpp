#include "curve.h"

Curve::Curve(shared_ptr<Plot> plot)
{
	m_weakPlot = weak_ptr<Plot>(plot);
}

Curve::Curve(const vector<double> &alpha, shared_ptr<Plot> plot)
{
	m_weakPlot = weak_ptr<Plot>(plot);
	addPoints(alpha);
	//cout << "Erstellt mit:" << plot << endl;
    
    
    // check if plot exists
	cout << "Erstellt mit:" << m_weakPlot.lock() << endl;
    
}

void Curve::printCurve() const
{
	cout << "|";
	for (auto const &it : m_values)
		cout << " " << it << " |";
	cout << endl
		 << endl;
}

void Curve::callPrint() const
{
    // check if plot exists
	if (shared_ptr<Plot> mSharedPlot = m_weakPlot.lock())
		mSharedPlot->print();
	else
		cout << "Error" << mSharedPlot << endl;
}

void Curve::addPoint(const double &alpha)
{
	m_values.push_back(alpha);
	callPrint();
}

void Curve::addPoints(const vector<double> &alpha)
{
	for (auto const &it : alpha)
	{
		m_values.push_back(it);
		callPrint();
	}
}

const size_t Curve::getSize() const
{
	return m_values.size();
}

const vector<double> Curve::getPoints() const
{
	return m_values;
}
