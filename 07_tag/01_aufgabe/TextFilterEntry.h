#pragma once
#include <regex>
#include <string>

class TextFilterEntry
{
 private:
    std::string m_regex;
  public:
    TextFilterEntry(const std::string &regex) : m_regex(regex){};

    const bool mask(const std::string &check) const;
};
