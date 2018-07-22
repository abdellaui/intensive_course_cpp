#include <iostream>

int main()
{
    const char str[] = "  Di  es i st   ein T e st     ";
    const int length = sizeof(str) / sizeof(str[0]);
    const char delimiter = ' ';
    char words[length][length] = {{""}};
    char currentChar;

    int i = 0;            // Index str
    int tokenCounter = 0; // Index words tokenCounter
    int tokenIndex = 0;   // Index words tokenIndex
    bool seenToken = false;

    while ((currentChar = str[i]) != '\0' && ++i)
    {

        if (currentChar == delimiter)
        {
            tokenIndex = 0;
            if (seenToken)
            {
                tokenCounter++;

                seenToken = false;
            }
        }
        else
        {
            words[tokenCounter][tokenIndex] = currentChar;
            seenToken = true;
            tokenIndex++;
        }
    }
    if (!seenToken)
        tokenCounter--;
    // Output
    std::cout << "String: " << str << std::endl;

    for (int i = 0; i < tokenCounter + 1; i++)
        std::cout << "Wort Nummer: " << i + 1 << ": " << words[i] << std::endl;
    std::cout << "Der String wurde in " << tokenCounter + 1 << " Token zerlegt!" << std::endl;

    return 0;
}