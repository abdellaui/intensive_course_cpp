#include <iostream>
#include "Recipy.h"

int Recipy::getTime() const
{
    return m_time;
}

const unsigned int &Recipy::getFlags() const
{
    return m_flags;
}

Recipy::Recipy(const std::string &title,
               const std::string &content,
               const int &time,
               const unsigned int &flags)
    : Document(title, content), m_time(time), m_flags(flags) {}

void Recipy::setTime(const int &time)
{
    Recipy::m_time = time;
}

void Recipy::setFlags(const unsigned int &flags)
{
    Recipy::m_flags = flags;
}

Recipy::Recipy(Recipy &&other) : Document(std::move(other)), m_time(other.m_time), m_flags(other.m_flags)
{
}

void Recipy::print()
{
    std::cout << "----------------------------- (Recipy)" << std::endl;
    std::cout << "Title: " << m_title << std::endl;
    std::cout << "Content: " << m_content << std::endl;
    std::cout << "Time: " << m_time << std::endl;

    std::cout << "Flags: ";
    std::cout << std::bitset<8>(m_flags) << std::endl;
}
