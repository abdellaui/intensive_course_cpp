#pragma once
#include "Filter.h"
#include "TextFilterEntry.h"

class NoteFilter : public Filter
{
  private:
    TextFilterEntry m_topicEntry;

  public:
    NoteFilter(const std::string &title,
                           const std::string &content,
                           const std::string &topic)
    : Filter(title, content), m_topicEntry(TextFilterEntry(topic)) {}
    bool match(const Document &doc) override;
};
