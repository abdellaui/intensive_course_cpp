#pragma once
#include <sstream>
#include "Document.h"

class Note : public Document
{
  private:
    std::string m_topic;

  public:
    Note(const std::string &title,
         const std::string &content,
         const std::string &topic);

    Note(Note &&other);

    void print() override;

    const std::string & getTopic() const;

    static Note load(std::istream &stream)
    {
        std::string title;
        std::string content;
        std::string topic;

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

        
        // read topic
        std::getline(stream, line);
        if (line.substr(0, 6) != "Topic:")
            throw std::runtime_error("Topic konnte nicht erkannt werden.");
        else
            topic = line.substr(6, line.length() - 6);

        
        
        return Note(title, content, topic);
    };
};
