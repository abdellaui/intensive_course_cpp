#pragma once
#include "plot.h"
using namespace std;

class Curve
{
  public:
	Curve(shared_ptr<Plot> plot);
	Curve(const vector<double> &alpha, shared_ptr<Plot> plot);

	void printCurve() const;
	void callPrint() const;
	void addPoint(const double &alpha);
	void addPoints(const vector<double> &alpha);
	const vector<double> getPoints() const;
	const size_t getSize() const;

  private:
	vector<double> m_values;
	weak_ptr<Plot> m_weakPlot;
};
