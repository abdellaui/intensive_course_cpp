#pragma once

#include "Document.h"
#include "TextFilterEntry.h"
#include <vector>

class Filter
{
  protected:
    TextFilterEntry m_titleEntry;
    TextFilterEntry m_contentEntry;

  public:
    Filter(const std::string &titleEntry,
           const std::string &contentEntry);

    virtual bool match(const Document &doc) = 0;
};
