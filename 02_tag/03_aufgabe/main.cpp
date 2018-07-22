#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string path = "/usr/test/./../.";
    std::string helpPath = path;
    std::string delimiter = "/";
    std::vector<std::string> words;
    std::size_t found = 0;
    int layer = 0;
    if (helpPath.at(0) != '/')
    {
        std::cout << path << " ist ungültig. Pfad beginnt mit /";
        return 0;
    }

    do
    {
        found = helpPath.find(delimiter);
        std::string token = helpPath.substr(0, found);
        if (!token.empty())
            words.push_back(token);
        helpPath = helpPath.substr(found + 1);

    } while (found != std::string::npos);

    for (int i = 0; i < words.size(); i++)
    {
        if (words.at(i) == "..")
            layer--;
        else if (words.at(i) != ".")
            layer++;
        if (layer < 0)
        {
            std::cout << path << " ist ungültig." << std::endl;
            return 0;
        }
    }
    std::cout << path << " ist gültig."<<( 1>>4) << std::endl;
    return 0;
}