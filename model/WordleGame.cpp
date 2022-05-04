#include "WordleGame.h"
#include <iostream>
#include "../model/resources/guessChecker.h"
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

vector<LetterPlacement> WordleGame::makeGuess(string guess) {
    transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
    vector<LetterPlacement> checks = checkGuess(guess.c_str(),this->wordToBeGuessed,this->wordLength);
    this->victory = 0;
    for(auto letter: checks) {
        cout << ", " << letter;
        if (letter == 0) {
            this->victory++;
        }
    }
    cout << endl;
    this->checkVictory();
    this->numberOfGuesses--;
    return checks;
    //Print out to console if the letter placement in the guess is Correct(0), Contains(1), Wrong(2)
}

    //True if you win, false otherwise.
    bool WordleGame::checkVictory() {
        return this->victory >= 5;
    }
    int WordleGame::getNumberOfGuesses() {
        return this->numberOfGuesses;
    }

}
