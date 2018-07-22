#pragma once
#include <map>
#include <ctime>
#include <iostream>
#include <string>
#include <ostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "termin.h"

class TerminManager
{

private:
  std::multimap<time_t, Termin *> m_termins;

  void listAllTermine() const;
  void listRelativeAviableTermine(const std::chrono::time_point<std::chrono::system_clock> &start) const;
  void listRelativePastTermine(const std::chrono::time_point<std::chrono::system_clock> &end) const;
  void listRangeOfTermine(const std::chrono::time_point<std::chrono::system_clock> &start,
                          const std::chrono::time_point<std::chrono::system_clock> &end) const;
  void listTerminOnDay(const std::chrono::time_point<std::chrono::system_clock> &now) const;
  void getLineTime(std::string &) const;
  void printSyntax(const std::string &) const;

public:
  TerminManager(const std::multimap<time_t, Termin *> &);
  bool createTermin();
  bool deleteTermin();
  void printPastTermine() const;
  void printFutureTermine() const;
  void printAllTermine() const;
  void printDayTermine() const;
  void printRangeTermine() const;
};
