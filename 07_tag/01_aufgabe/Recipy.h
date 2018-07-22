#pragma once
#include <string>
#include <istream>
#include <sstream>
#include <cmath>
#include "Document.h"

class Recipy : public Document
{
  private:
    int m_time;
    unsigned int m_flags;

  public:
    Recipy(const std::string &title,
           const std::string &content,
           const int &time,
           const unsigned int &flags);

    Recipy(Recipy &&other);

    void print() override;

    Recipy &operator=(Recipy &&other) = default;

    int getTime() const;

    const unsigned int &getFlags() const;

    void setTime(const int &time);

    void setFlags(const unsigned int &flags);

    static Recipy load(std::istream &stream)
    {
        std::string title;
        std::string content;
        int time;
        unsigned int flag;

        std::string line;

        
        // read title
        std::getline(stream, line);
        if (line.substr(0, 6) != "Title:")
            throw std::runtime_error("Titel konnte nicht erkannt werden.");
        else
            title = line.substr(6, line.length() - 7);

        
        // read content
        std::getline(stream, line);
        if (line.substr(0, 8) != "Content:")
            throw std::runtime_error("Content konnte nicht erkannt werden.");
        else
            content = line.substr(8, line.length() - 9);

        
        // read time
        std::getline(stream, line);
        if (line.substr(0, 5) != "Time:")
            throw std::runtime_error("Time konnte nicht erkannt werden.");
        try
        {
            // from string to int
            std::stringstream ss(line.substr(5, line.length() - 5));
            ss >> time;
        }
        catch (std::exception & exc)
        {
            throw std::runtime_error("Time konnte nicht erkannt werden.");
        }
        
        
        // read flag
        std::getline(stream, line);
        if (line.substr(0, 6) != "Flags:")
            throw std::runtime_error("Flag konnte nicht erkannt werden.");
        try
        {
            std::string input = line.substr(6, line.length() - 6);
            flag = static_cast<unsigned int>(std::bitset<8>(input).to_ulong());
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Flag konnte nicht erkannt werden.");
        }
        
        

        return Recipy(title, content, time, flag);
    }
};
