#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string str = " Dies ist ein  Test     ";
    std::string helpStr = str;
    std::string delimiter = " ";
    std::vector<std::string> words;
    std::size_t found = 0;

    do
    {
        found = helpStr.find(delimiter);
        std::string token = helpStr.substr(0, found);
        if (!token.empty())
            words.push_back(token);
        helpStr = helpStr.substr(found + 1);

    } while (found != std::string::npos);

    // Output
    std::cout << "String: " << str << std::endl;
    for (int i = 0; i < words.size(); i++)
        std::cout << "Wort Nummer: " << i + 1 << ": " << words.at(i) << std::endl;
    std::cout << "Der String wurde in " << words.size() << " Token zerlegt!" << std::endl;

    return 0;
}