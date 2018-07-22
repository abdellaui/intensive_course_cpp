#include "terminmanager.h"
std::function<const bool(const std::chrono::time_point<std::chrono::system_clock> &)>
_dateIsNotReal = [](const std::chrono::time_point<std::chrono::system_clock> &a)
                    { return a.time_since_epoch().count() == -1000000; };

std::function<const bool(const std::chrono::time_point<std::chrono::system_clock> &,
                         const std::chrono::time_point<std::chrono::system_clock> &)>
_dateIsNotAfter = [](const std::chrono::time_point<std::chrono::system_clock> &a,
                     const std::chrono::time_point<std::chrono::system_clock> &b)
                    { return (a.time_since_epoch().count() - b.time_since_epoch().count()) > 0; };

TerminManager::TerminManager(const std::multimap<time_t, Termin *> &termins) : m_termins(termins) {}

bool TerminManager::createTermin()
{
    std::string start, end, description;
    std::cout << "Geben Sie das Startdatum ein:" << std::endl;
    const std::string syntax = "%d.%m.%Y %H:%M";
    printSyntax(syntax);
    getLineTime(start);

    std::cout << "Geben Sie das Enddatum ein:" << std::endl;
    printSyntax(syntax);
    getLineTime(end);
    std::cout << "Geben Sie die Beschreibung ein:" << std::endl;
    getLineTime(description);

    Termin *newTermin = Termin::createInstance(start, end, description);

    //time_t terminStart = std::chrono::system_clock::to_time_t(newTermin->getStart());
    //time_t terminEnd = std::chrono::system_clock::to_time_t(newTermin->getEnd());
    //std::cout << std::put_time(localtime(&terminStart),"%d.%m.%Y %H:%M") << " - ";
    //std::cout << std::put_time(localtime(&terminEnd),"%d.%m.%Y %H:%M") << std::endl;

    if (_dateIsNotReal(newTermin->getStart()) || _dateIsNotReal(newTermin->getEnd()))
    {
        std::cout << "Erstellen des Termins fehlgeschlagen." << std::endl;
        delete newTermin;
        return false;
    }

    for (const auto &it : m_termins)
    {
        if (newTermin->collides(*it.second))
        {
            std::cout << "Termin kollidiert mit Termin " + it.second->getDescription() + "." << std::endl;
            delete newTermin;
            return false;
        }
    }

    m_termins.insert(std::pair<time_t, Termin *>(std::chrono::system_clock::to_time_t(newTermin->getStart()), newTermin));

    return true;
}
bool TerminManager::deleteTermin()
{
    listAllTermine();
    std::cout << "Gebe die #ID an:" << std::endl;
    std::string input;
    getLineTime(input);
    time_t id;
    std::stringstream ss(input);
    if (ss >> id)
    {
        std::multimap<time_t, Termin *>::iterator it = m_termins.find(id);
        if (it != m_termins.end())
        {

            std::cout << "Termin " << *it->second << std::endl
                      << " ** DELETED **" << std::endl;
            m_termins.erase(it);
            delete it->second;
        }
        else
        {
            std::cout << "ID nicht gefunden!" << std::endl;
        }
    }
    else
    {
        std::cout << "Gueltige ID angeben" << std::endl;
    }
    return false;
}

void TerminManager::listAllTermine() const
{
    bool hasEntry = false;
    for (const auto &it : m_termins)
    {
        std::cout << "#ID: " << it.first << "\n"
                  << *it.second << std::endl
                  << std::endl;
        hasEntry = true;
    }
    if (!hasEntry)
        std::cout << "Keine Termine gefunden..." << std::endl;
}

void TerminManager::listRelativeAviableTermine(const std::chrono::time_point<std::chrono::system_clock> &start) const
{
    if (_dateIsNotReal(start))
    {
        std::cout << "Ungueltiges Datum." << std::endl;
        return;
    }
    bool hasEntry = false;
    for (const auto &it : m_termins)
    {
        if (it.second->getStart() >= start)
        {
            std::cout << "#ID: " << it.first << "\n"
                      << *it.second << std::endl
                      << std::endl;
            hasEntry = true;
        }
    }
    if (!hasEntry)
        std::cout << "Keine Termine gefunden..." << std::endl;
}

void TerminManager::listRelativePastTermine(const std::chrono::time_point<std::chrono::system_clock> &end) const
{
    if (_dateIsNotReal(end))
    {
        std::cout << "Ungueltiges Datum." << std::endl;
        return;
    }
    bool hasEntry = false;

    for (const auto &it : m_termins)
    {
        if (it.second->getEnd() <= end)
        {
            std::cout << "#ID: " << it.first << "\n"
                      << *it.second << std::endl
                      << std::endl;
            hasEntry = true;
        }
    }
    if (!hasEntry)
        std::cout << "Keine Termine gefunden..." << std::endl;
}

void TerminManager::listRangeOfTermine(const std::chrono::time_point<std::chrono::system_clock> &start,
                                       const std::chrono::time_point<std::chrono::system_clock> &end) const
{
    if (_dateIsNotReal(start) || _dateIsNotReal(end) || _dateIsNotAfter(start, end))
    {
        std::cout << "Ungueltiges Datum." << std::endl;
        return;
    }
    bool hasEntry = false;

    for (const auto &it : m_termins)
    {
        if (it.second->getStart() >= start && it.second->getEnd() <= end)
        {
            std::cout << "#ID: " << it.first << "\n"
                      << *it.second << std::endl
                      << std::endl;
            hasEntry = true;
        }
    }
    if (!hasEntry)
        std::cout << "Keine Termine gefunden..." << std::endl;
}
void TerminManager::listTerminOnDay(const std::chrono::time_point<std::chrono::system_clock> &now) const
{
    if (_dateIsNotReal(now))
    {
        std::cout << "Ungueltiges Datum." << std::endl;
        return;
    }
    bool hasEntry = false;

    time_t nowT = std::chrono::system_clock::to_time_t(now);
    std::stringstream nowDatum;
    nowDatum << std::put_time(localtime(&nowT), "%d.%m.%Y");
    std::cout << "Termine am: " << std::put_time(localtime(&nowT), "%d.%m.%Y") << std::endl;
    for (const auto &it : m_termins)
    {
        time_t currentT = std::chrono::system_clock::to_time_t(it.second->getStart());
        std::stringstream currentDatum;
        currentDatum << std::put_time(localtime(&currentT), "%d.%m.%Y");
        if (nowDatum.str() == currentDatum.str())
        {
            std::cout << "#ID: " << it.first << "\n"
                      << *it.second << std::endl
                      << std::endl;
            hasEntry = true;
        }
    }
    if (!hasEntry)
        std::cout << "Keine Termine gefunden..." << std::endl;
}

void TerminManager::printPastTermine() const
{
    std::cout << "Vergangene Termine:" << std::endl;
    listRelativePastTermine(readTimeFromString("jetzt"));
}

void TerminManager::printFutureTermine() const
{
    std::cout << "Vorstehende Termine:" << std::endl;
    listRelativeAviableTermine(readTimeFromString("jetzt"));
}

void TerminManager::printAllTermine() const
{
    std::cout << "Alle Termine:" << std::endl;
    listAllTermine();
}

void TerminManager::printDayTermine() const
{
    std::string now;
    const std::string syntax = "%d.%m.%Y %H:%M";
    std::cout << "Tag eingeben:" << std::endl;
    printSyntax(syntax);
    getLineTime(now);
    listTerminOnDay(readTimeFromString(now));
}

void TerminManager::printRangeTermine() const
{
    std::string start, end;
    std::cout << "Bestimmen Sie die Zeitspanne:" << std::endl;

    std::cout << "Geben Sie das Startdatum ein:" << std::endl;
    const std::string syntax = "%d.%m.%Y %H:%M";
    printSyntax(syntax);
    getLineTime(start);

    std::cout << "Geben Sie das Enddatum ein:" << std::endl;
    printSyntax(syntax);
    getLineTime(end);

    listRangeOfTermine(readTimeFromString(start), readTimeFromString(end));
}

void TerminManager::getLineTime(std::string &input) const
{
    std::cin.sync();
    std::getline(std::cin, input);
    //std::cout << input << std::endl;
}

void TerminManager::printSyntax(const std::string &syntax) const
{
    std::cout << "(Syntax: " << syntax << " oder [jetzt/morgen])" << std::endl;
}
