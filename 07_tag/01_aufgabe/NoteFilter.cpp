#include <vector>
#include "NoteFilter.h"
#include "Note.h"

bool NoteFilter::match(const Document &doc)
{
    const Note *docNote;
    try
    {
        docNote = &(dynamic_cast<const Note &>(doc));
    }
    catch (std::bad_cast & exc)
    {
        return false;
    }
    return (m_titleEntry.mask(docNote->getTitle()) &&
           m_contentEntry.mask(docNote->getContent()) &&
           m_topicEntry.mask(docNote->getTopic()));
}
