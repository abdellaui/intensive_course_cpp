#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <ostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <functional>

class Termin
{
  private:
    std::chrono::time_point<std::chrono::system_clock> m_start;
    std::chrono::time_point<std::chrono::system_clock> m_end;
    std::string m_description;

  public:
    Termin(const std::chrono::time_point<std::chrono::system_clock> &start,
           const std::chrono::time_point<std::chrono::system_clock> &end,
           const std::string &description);
    static Termin *createInstance(const std::string &m_start,
                                  const std::string &m_end,
                                  const std::string &m_description);

    bool collides(Termin &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Termin &termin);
    friend inline std::chrono::time_point<std::chrono::system_clock> readTimeFromString(const std::string &input);
    const std::chrono::time_point<std::chrono::system_clock> &getStart() const;
    const std::chrono::time_point<std::chrono::system_clock> &getEnd() const;
    const std::string &getDescription() const;
};

std::chrono::time_point<std::chrono::system_clock> readTimeFromString(const std::string &input)
{
    if (input == "jetzt")
    {
        return std::chrono::system_clock::now();
    }

    if (input == "morgen")
    {
        return std::chrono::system_clock::now() + std::chrono::hours(24);
    }
    std::tm tm = {};
    std::stringstream ss(input);
    ss >> std::get_time(&tm, "%d.%m.%Y %H:%M");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm)); // time_to to sys time
}
