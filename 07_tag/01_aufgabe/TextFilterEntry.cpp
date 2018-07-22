#include "TextFilterEntry.h"
const bool TextFilterEntry::mask(const std::string &input) const
{
    if (!m_regex.empty())
        return std::regex_match(input.begin(),
                                input.end(),
                                std::regex(m_regex, std::regex_constants::ECMAScript|std::regex_constants::icase));
    else
        return true;
}

