#pragma once
#include <regex>
#include <string>

class DurationFilterEntry
{
  private:
    std::string m_regex;

  public:
    DurationFilterEntry(const std::string &regex) : m_regex(regex) {}
    
    const bool mask(const int & input) const;
};
