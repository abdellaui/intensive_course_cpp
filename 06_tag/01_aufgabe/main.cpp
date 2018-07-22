#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <string>

using namespace std;

void countWordsByReading(ifstream &file, map<string, int> &countOfWords)
{
    string currentWord;
    while (file >> currentWord)
    {
        currentWord = regex_replace(currentWord, regex("\\.|\\,|-|\"|\'"), "");
        // . , - " '-> (leer)
        currentWord = regex_replace(currentWord, regex("\\xE4|\\xC4"), "ä");
        // ä    | Ä         -> ä
        currentWord = regex_replace(currentWord, regex("\\xDC|\\xFC"), "ö");
        // ö    | Ö         -> ö
        currentWord = regex_replace(currentWord, regex("\\xD6|\\xF6"), "ü");
        // ü    | Ü         -> ü
        currentWord = regex_replace(currentWord, regex("\\xDF"), "ß");
        // ß                -> ü
        currentWord = regex_replace(currentWord, regex("[\222-\226]"), "");


        // if currentWord
        if (currentWord.empty())
            continue;

        // lowercase the word
        transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);

        // insert or update word
        map<string, int>::iterator it = countOfWords.find(currentWord);
        if (it == countOfWords.end()) // if currentOfWords not in our countOfWords, so insert please
            countOfWords.insert(pair<string, int>(currentWord, 1));
        else
            it->second += 1; // otherwise inkrement second
    }
}

int main()
{
    // to map word to count  (word->count)
    map<string, int> countOfWords;

    ifstream file1;
    file1.exceptions(ios_base::failbit);

    ifstream file2;
    file2.exceptions(ios_base::failbit);

    try
    {
        file1.open("text1.txt");
        file2.open("text2.txt");
    }
    catch (const ifstream::failure &exc)
    {
        cout << "file doesnt exist or could open!" << endl;
    };

    countWordsByReading(file1, countOfWords);
    countWordsByReading(file2, countOfWords);

    // to sort on key->value (count->word)
    multimap<int, string> result;

    // swap key and value
    for (map<string, int>::iterator it = countOfWords.begin(); it != countOfWords.end(); it++)
        result.insert(pair<int, string>(it->second, it->first));

    // print
    cout << "Word"
         << "\t\t"
         << "Count" << endl;
    cout << "======================" << endl;

    //for (multimap<int, string>::iterator it = result.begin(); it != result.end(); it++)
    for (multimap<int, string>::reverse_iterator it = result.rbegin(); it != result.rend(); it++)
        cout << it->first << "\t\t" << it->second << endl;

    return 0;
}
