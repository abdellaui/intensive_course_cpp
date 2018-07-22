#include "FlagFilterEntry.h"

const bool FlagFilterEntry::mask(const unsigned int &input) const
{
    if (m_regex != 0)
        return (input & m_regex) == m_regex;  // test flag input and regex
    return true;
}

