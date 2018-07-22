#include <iostream>
#include "Note.h"

Note::Note(const std::string &title,
           const std::string &content,
           const std::string &topic) : Document(title, content), m_topic(topic) {}

const std::string & Note::getTopic() const
{
    return m_topic;
}

Note::Note(Note &&other) : Document(std::move(other)),
                           m_topic(std::move(other.m_topic)) {}

void Note::print()
{
    std::cout << "----------------------------- (Note)" << std::endl;
    std::cout << "Title: " << m_title << std::endl;
    std::cout << "Content: " << m_content << std::endl;
    std::cout << "Topic: " << m_topic << std::endl;
}
