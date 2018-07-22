#include "DurationFilterEntry.h"

const bool DurationFilterEntry::mask(const int &input) const
{
    if (m_regex.empty())
        return true;

    int readIntFromString = std::stoi(m_regex.substr(1, m_regex.length() - 1));
    
    if (m_regex.at(0) == '!')
    {
        return readIntFromString != input;
    }

    else if (m_regex.at(0) == '=')
    {
        return readIntFromString == input;
    }

    else if (m_regex.at(0) == '<')
    {
        return readIntFromString > input;
    }

    else if (m_regex.at(0) == '>')
    {
        return readIntFromString < input;
    }

    return false;
}

