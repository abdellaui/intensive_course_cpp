#include <string>
#include <mutex>
#include <functional>

#include "plot.h"
#include "curve.h"
#include "FunctionTimer.h"
#include "spline.h"

shared_ptr<Plot> myPlot;
vector<thread> myThreads;

using namespace std;
double elapsedTime;

double myMinimum(Curve myCurve, double stepSize)
{
    double minimum =0.;
    /* to be continiued */
    return minimum;
}

double integral(Curve myCurve, double stepSize)
{
    double summe = 0.;
    /* to be continiued */
    return summe;
}

int main()
{
    cout << "Kurven:" << endl
         << endl;

    vector<double> vi;
    vector<double> vs;
    for (int i = 0; i < 20; i++)
    {
        vi.push_back((double)i + (double)i * 1.3 + 0.9);
        vs.push_back((double)i * 2.1);
    }

    myPlot = make_shared<Plot>();

    Curve curvi(vi, myPlot);
    Curve curvs(vs, myPlot);

    myPlot->addCurve(make_shared<Curve>(curvi));
    myPlot->addCurve(make_shared<Curve>(curvs));

    myPlot->print();


    myPlot->getCurve().addPoint(23.0);

    return 0;
}
