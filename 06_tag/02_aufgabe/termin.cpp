#include "termin.h"
std::function<const bool(const std::chrono::time_point<std::chrono::system_clock> &)>
dateIsNotReal = [](const std::chrono::time_point<std::chrono::system_clock> &a)
                    { return a.time_since_epoch().count() == -1000000; };

std::function<const bool(const std::chrono::time_point<std::chrono::system_clock> &, const std::chrono::time_point<std::chrono::system_clock> &)>
dateIsNotAfter = [](const std::chrono::time_point<std::chrono::system_clock> &a,
                    const std::chrono::time_point<std::chrono::system_clock> &b)
                    { return (a.time_since_epoch().count() - b.time_since_epoch().count()) > 0; };

Termin::Termin(const std::chrono::time_point<std::chrono::system_clock> &start,
               const std::chrono::time_point<std::chrono::system_clock> &end,
               const std::string &description)
    : m_start(start), m_end(end), m_description(description) {}

Termin *Termin::createInstance(const std::string &start,
                               const std::string &end,
                               const std::string &description)
{
    std::chrono::time_point<std::chrono::system_clock> startPoint = readTimeFromString(start);
    std::chrono::time_point<std::chrono::system_clock> endPoint = readTimeFromString(end);

    if (dateIsNotReal(startPoint) || dateIsNotReal(endPoint) || dateIsNotAfter(startPoint, endPoint))
        std::cout << "Eintrag für " << start << " / " << end << " konnte nicht korrekt erzeugt werden. Daten fehlerhaft." << std::endl;

    return new Termin(startPoint, endPoint, description);
}

bool Termin::collides(Termin &other) const
{
    /*
     () other
     [] this
     
     ([]) false
     
     ()[] true
     []() true
     */

    return !(std::chrono::system_clock::to_time_t(other.getEnd()) <= std::chrono::system_clock::to_time_t(getStart()) || std::chrono::system_clock::to_time_t(getEnd()) <= std::chrono::system_clock::to_time_t(other.getStart()));
}

std::ostream &operator<<(std::ostream &os, const Termin &termin)
{
    time_t start = std::chrono::system_clock::to_time_t(termin.m_start);
    time_t end = std::chrono::system_clock::to_time_t(termin.m_end);
    os << "Start: " << std::put_time(localtime(&start), "%d.%m.%Y %H:%M") << "\n";
    os << "End: " << std::put_time(localtime(&end), "%d.%m.%Y %H:%M") << "\n";
    os << "Beschreibung: " << termin.m_description;
    return os;
}

const std::chrono::time_point<std::chrono::system_clock> &Termin::getStart() const
{
    return m_start;
}

const std::chrono::time_point<std::chrono::system_clock> &Termin::getEnd() const
{
    return m_end;
}

const std::string &Termin::getDescription() const
{
    return m_description;
}
