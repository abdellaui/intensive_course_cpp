#include <iostream>
#include <fstream>
#include "listFilesInDirectory.h"
#include "Recipy.h"
#include "Note.h"
#include "NoteFilter.h"
#include "RecipyFilter.h"


enum RecipeFlags{
    DESSERT         = 0x01,
    HAUPTSPEISE     = 0x02,
    VORSPEISE       = 0x04,
    SUPPE           = 0x08,
    VEGATARISCH     = 0x10,
    VEGAN           = 0x20,
    NZ              = 0x40,
    NOT_NZ          = 0x80
};

std::vector<Document *> documents;

std::vector<Document *> runFilter(std::vector<Document *> in,
                                  Filter &filter)
{
    std::vector<Document *> out;

    std::copy_if(in.begin(), in.end(), std::back_inserter(out), [&filter](Document *doc) {
        return filter.match(*doc);
    });

    return out;
}

std::vector<Document *> runFiltersAnd(std::vector<Filter *> filters)
{
    std::vector<Document *> in = documents;

    for (Filter *f : filters)
        in = runFilter(in, *f);

    return in;
}

std::vector<Document *> runFiltersOr(std::vector<Filter *> filters)
{
    /*
     es muss nur ein filter gelten.
     wir iterieren durch die filter und fügen bei match des filters
     die documente in out
     */
    std::vector<Document *> out;

    for (Filter *f : filters)
    {
        // iteriere filter und schreibe es in curr
        std::vector<Document *> curr = runFilter(documents, *f);

        
        for (Document *doc : curr)
            // iteriere curr und füge es in out
            if (std::find(out.begin(), out.end(), doc) == out.end())
                out.push_back(doc);
    }

    return out;
}

void readFiles()
{
    std::cout << "#######################################################"<<std::endl;
    std::cout << "\t\t Read all files: "<< std::endl;
    std::cout << "#######################################################"<<std::endl<<std::endl;
    auto files = listFilesInDirectory("files_recipe_note");

    for (std::string file : files)
    {
        std::ifstream stream(file);

        Document *doc;
        
        // read first line
        std::string firstLine;
        std::getline(stream, firstLine);
        if (firstLine == "class Recipe\r")
            try
            {
                /*
                 Recipy(title, content, time, flag) : public Document(title, content)
                 
                 title:     (string)
                 content:   (string)
                 time:      (int)
                 flag:      (int)
                 */
                
                doc = new Recipy(std::move(Recipy::load(stream)));
            }
            catch (std::runtime_error & exc)
            {
                std::cout <<  "( ignored) \t\t" << file << std::endl;
                continue;
            }
        else if (firstLine == "class Note\r")
            try
            {
                /*
                 Note(title, content, topic) : public Document(title, content)
                 
                 title:     (string)
                 content:   (string)
                 topic:     (string)
                 */
                doc = new Note(std::move(Note::load(stream)));
            }
            catch (std::runtime_error & exc)
            {
                std::cout <<  "( ignored) \t\t" << file << std::endl;
                continue;
            }
        else
        {
            std::cout <<  "( ignored) \t\t" << file << std::endl;
            continue;
        }

        stream.close();
        std::cout <<  "(accepted) \t\t" << file << std::endl;
        documents.push_back(doc);
    }
}

void filter(Filter *f, std::string name)
{

    std::vector<Filter *> filters;

    filters.push_back(f);
    std::cout << "#######################################################"<<std::endl;
    std::cout << "\t\t Filterergebnis: " << name << std::endl;
    std::cout << "#######################################################"<<std::endl<<std::endl;
    for (Document *doc : runFiltersOr(filters))
    {
        doc->print();
        std::cout << std::endl;
    }
}

int main()
{
    readFiles();
    
    std::cout <<std::endl
    << "#######################################################"<<std::endl;
    std::cout << "\t\t Print valid files: "  << std::endl;
    std::cout << "#######################################################"<<std::endl<<std::endl;
    for (Document *doc : documents)
        doc->print();

    std::cout << std::endl;
    std::cout << std::endl;

    /*
     RecipyFilter(title, content, time, flag) : public Filter(title, content)
     
     title      : (string) regex with wildcards ignored case
     content    : (string) regex with wildcards ignored case
     time       : (string) (first char operand {!, =, <, >}) (int value)
     flag       : (string) RecipyFlags
     */
    
        RecipyFilter brot(".*brot.*", "", "", "");
        RecipyFilter brotNicht("^(?!.*brot).*$", "", "", "");
        RecipyFilter brot30Min(".*brot.*", "", "<30", "");
    
          RecipyFilter vorspeise("", "", "", std::bitset<8>(VORSPEISE).to_string());
          RecipyFilter veganVorspeise("", "", "", std::bitset<8>(VORSPEISE | VEGAN).to_string());
    //
        RecipyFilter gulasch("Gulasch", "", ">60", std::bitset<8>(HAUPTSPEISE).to_string());
    //
    
    
    /*
     NoteFilter(title, content, topic) : public Filter(title, content)
     
     title      : (string) regex with wildcards ignored case
     content    : (string) regex with wildcards ignored case
     topic      : string) regex with wildcards ignored case
     */
    
    
    
        NoteFilter kochen("", "", ".*Kochen.*");
        NoteFilter kochenUndBrot(".*brot.*", "", ".*Kochen.*");
    //
    //
    
//
//        filter(&brot, "Brot");
//        filter(&brotNicht, "BrotNicht");
//        filter(&brot30Min, "Brot30Min");
//
//        filter(&vorspeise, "Vorspeise");
//        filter(&veganVorspeise, "VorspeiseVegan");
//
//        filter(&gulasch, "Gulasch");
//
//        filter(&kochen, "Kochen");
//        filter(&kochenUndBrot, "KochenUndBrot");
    //
//
    std::vector<Filter *> filters;

    filters.push_back(&brot);
    filters.push_back(&kochen);
    std::cout <<"****+++++***"<<std::endl;
    for (Document *doc : runFiltersAnd(filters))
    //for (Document *doc : runFiltersOr(filters))
    {
        doc->print();
        std::cout << std::endl;
    }

    return 0;
}
