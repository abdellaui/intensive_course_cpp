#pragma once
#include <string>
#include <iostream>

class Document
{
  protected:
    std::string m_title;
    std::string m_content;

  public:
    void setTitle(const std::string &title);

    void setContent(const std::string &content);

    Document(const std::string &title,
             const std::string &content)
    : m_title(title), m_content(content) {}
    

    Document(const Document &other) = delete;

    Document(Document &&other) = default;
    
    virtual ~Document();
    
    const std::string &getTitle() const;

    const std::string &getContent() const;

    virtual void print() = 0;
};
