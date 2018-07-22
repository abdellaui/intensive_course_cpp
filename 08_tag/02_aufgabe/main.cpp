#include <thread>
#include <memory>
#include <random>
#include "warteschlange.h"
#include "besucher.h"

using namespace std;

typedef shared_ptr<Besucher> BesucherPtr;
mutex consoleMtx;

vector<thread> Schalter;

bool generatorFlag = true;

Warteschlange<BesucherPtr> Schlange(10);

void printAufgabe(const string &str, const int &uid)
{
    consoleMtx.lock();
    cout << str << uid << endl;
    consoleMtx.unlock();
}

void neuerKunde()
{
    unsigned int seed = (unsigned int) std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine defRan(seed);
    int millisGeneratorNeed;
    int visitorNeedTime;
    int uId = 0;  // inkrement by iteration
    while (generatorFlag)
    {
        // gen random need time for generator
        millisGeneratorNeed = defRan();
        millisGeneratorNeed = (millisGeneratorNeed % 1000) + 1000;
        if (millisGeneratorNeed < 0)  // betrag
            millisGeneratorNeed = -1 * millisGeneratorNeed;
        printAufgabe("rand1:", millisGeneratorNeed);

        // gen random neet time for visitor
        visitorNeedTime = defRan();
        visitorNeedTime = (visitorNeedTime % 10000) + 1500;
        if (visitorNeedTime < 0) // betrag
            visitorNeedTime = -1 * visitorNeedTime;
        printAufgabe("rand2:", visitorNeedTime);

        
        // push visitor in queue
        BesucherPtr besucher = make_shared<Besucher>(visitorNeedTime, uId);
        if (Schlange.enqueue(besucher))
            printAufgabe("Kunden hinzugefuegt: ", uId);
    
        // wait for time needed by genetor
        this_thread::sleep_for(chrono::milliseconds{millisGeneratorNeed});
        uId++;
    }
}

void bedieneKunde()
{
    while (1)
    {
        BesucherPtr currentBesucher;
        if (!Schlange.dequeue(currentBesucher))
        {
            if (nullptr != currentBesucher)
                currentBesucher->serve();
            break;
        }
        else
        {
            currentBesucher->serve();
            printAufgabe("Kunden bedient: ", currentBesucher->getUID());
        }
    }
}

void open()
{
    Schalter.push_back(thread{ []() { bedieneKunde(); } });
}

int main()
{
    thread generator{[]() { neuerKunde(); }};
    open();
    this_thread::sleep_for(chrono::milliseconds{5000});
    open();
    open();
    open();
    this_thread::sleep_for(chrono::milliseconds{10000});
    generatorFlag = false;
    // delete schlange;
    Schlange.stop();

    generator.join();

    for (auto &it : Schalter)
    {
        // wait for all Schalters to finish
        it.join();
    }

    return 0;
}
