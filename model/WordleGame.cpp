#include "WordleGame.h"
#include <iostream>
#include "guessChecker.h"
#include <vector>

namespace Wordle
{

WordleGame::WordleGame(int wordLength)
{
    this->wordLength = wordLength;
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
    cout<< "The word to be guessed is: ++++++" << this->wordToBeGuessed<<" +++++++++" <<endl;
}

void WordleGame::makeGuess(string guess) {
    vector<LetterPlacement> checks = checkGuess(guess.c_str(),this->wordToBeGuessed,this->wordLength);
    for(auto letter: checks) {
        cout << ", " << letter;
    }
    cout << endl;
    this->numberOfGuesses--;
    //Print out to console if the letter placement in the guess is Correct(0), Contains(1), Wrong(2)
}
}
