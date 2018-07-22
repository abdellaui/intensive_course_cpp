#pragma once
#include <regex>
#include <string>

class FlagFilterEntry
{
  private:
    unsigned int m_regex;

  public:
    FlagFilterEntry(const unsigned int & regex) : m_regex(regex){};

    const bool mask(const unsigned int & in) const;
};
