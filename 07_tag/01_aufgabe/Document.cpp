#include "Document.h"
Document::~Document(){};

const std::string &Document::getTitle() const
{
    return m_title;
}

const std::string &Document::getContent() const
{
    return m_content;
}

void Document::setTitle(const std::string &title)
{
    Document::m_title = title;
}

void Document::setContent(const std::string &content)
{
    Document::m_content = content;
}
