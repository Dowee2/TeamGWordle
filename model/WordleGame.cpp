#include "WordleGame.h"
#include <iostream>

namespace Wordle{

WordleGame::WordleGame(int wordLength)
{
    vector<string> wordsInPlay = this->dictionary->getAllWordsOfLength(wordLength);
    this->generateWord(wordsInPlay);

}

WordleGame::~WordleGame()
{
    //dtor
}

void WordleGame::generateWord(vector<string>& words)
{
    srand((unsigned)time(NULL));
    int random = rand()%words.size();

    this->wordToBeGuessed = words[random].c_str();

    //Uncomment to see what would was generated to be guessed
    cout<< "The word to be guessed is: " << this->wordToBeGuessed <<endl;
}
}
