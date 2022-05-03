#include "Dictionary.h"
#include <bits/stdc++.h>
namespace Wordle
{
Dictionary::Dictionary()
{
    this->generateVocabulary();
}

Dictionary::~Dictionary()
{

}

void Dictionary::generateVocabulary()
{
    fstream inputFile;
    string filepath = "model/resources/dictionary.txt";
    inputFile.open(filepath.c_str());

    if(inputFile.good())
    {
        string word;
        while (inputFile >> word)
        {
            this->addWord(word);
        }
    }
    else
    {
        cout << "File does not exist at : " << filepath << endl;
    }
    inputFile.close();
}

void Dictionary::addWord(string& word)
{
    if(this->vocabulary.find(word.length()) != this->vocabulary.end())
    {
        this->vocabulary.at(word.length()).push_back(word);
    }
    else
    {
        vector<string> vocabulary{word};
        this->vocabulary.insert(std::pair<int,vector<string>>(word.length(), vocabulary));
    }
}

vector<string> Dictionary::getAllWordsOfLength(int wordlength)
{
    return this->vocabulary.at(wordlength);
}

void Dictionary::Debug()
{
    for(auto const& veocab : this->vocabulary)
    {
        int countColumns = 0;

        for(string currWord : veocab.second)
        {

            countColumns++;


        }
        cout <<"There are " << countColumns << " that have " <<veocab.first<< " characters" <<endl;
    }

}
}
