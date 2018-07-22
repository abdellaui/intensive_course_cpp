#include "plot.h"
#include "curve.h"

//extern vector<thread> myThreads;

void Plot::addCurve(const shared_ptr<Curve> delta)
{
	m_curves.push_back(delta);
}

// Prints all curves
void Plot::print() const
{
	for (auto const &it : m_curves)
		it->printCurve();
}

void Plot::executeOnOne(vector< function<double(Curve, double)> > &obj,
						const unsigned int &index,
						const double &step,
						const bool &inThread)
{
	if (m_curves.size() < index)
		return;

	vector<double> result_No_Thread;
	vector<future<double>> resultThread;
    
    /* to be continiued */
}

void Plot::executeOnOne(vector<packaged_task<double(Curve, double)>> &obj,
						const unsigned int &index,
						const double &step,
						const bool &inThread)
{
	if (m_curves.size() < index)
		return;
	vector<future<double>> results;

	/* to be continiued */

}

void Plot::executeOnAll(function<double(Curve, double)> &obj,
						const double &step,
						const bool &inThread)
{
	vector<double> ergebnis;
	vector< future<double> > results;
    /* to be continiued */
}

Curve &Plot::getCurve() const
{
	return *m_curves.at(0);
}
