#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include <functional>
#include <thread>
#include <future>

class Curve; // compiler shut up

using namespace std;

class Plot
{
public:
  void addCurve(const shared_ptr<Curve> delta);
  // Prints all curves
  void print() const;
  void executeOnOne(vector<function<double(Curve, double)>> &obj,
                    const unsigned int &index,
                    const double &step,
                    const bool &inThread);
  // overloading with packaged_task
  void executeOnOne(vector<packaged_task<double(Curve, double)>> &obj,
                    const unsigned int &index,
                    const double &step,
                    const bool &inThread);

  void executeOnAll(function<double(Curve, double)> &obj,
                    const double &step,
                    const bool &inThread);
  Curve &getCurve() const;

private:
  vector<shared_ptr<Curve>> m_curves;
};
