#ifndef WORDLEGAME_H
#define WORDLEGAME_H
#include "../model/resources/guessChecker.h"
#include "../model/resources/Dictionary.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

namespace model
{

class WordleGame
{
public:
    WordleGame(int wordLength);
    virtual ~WordleGame();
    vector<LetterPlacement> makeGuess(string guess);
    int getNumberOfGuesses();

protected:

private:
    int victory;
    Dictionary* dictionary = new Dictionary();;
    int wordLength;
    const char* wordToBeGuessed;
    void playerGuess(string guess);
    void generateWord(vector<string> &words);
    int numberOfGuesses = 6;
    bool checkVictory();

};
}

#endif // WORDLEGAME_H
