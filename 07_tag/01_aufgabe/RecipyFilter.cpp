#include "RecipyFilter.h"
#include "Recipy.h"

bool RecipyFilter::match(const Document &doc)
{
    const Recipy *docRecipy;
    try
    {
        docRecipy = &(dynamic_cast<const Recipy &>(doc));
    }
    catch (std::bad_cast & exc)
    {
        return false;
    }
    return (m_titleEntry.mask(docRecipy->getTitle()) &&
           m_contentEntry.mask(docRecipy->getContent()) &&
           m_timeEntry.mask(docRecipy->getTime()) &&
           m_flagEntry.mask(docRecipy->getFlags()));
}
