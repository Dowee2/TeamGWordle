#ifndef WORDLEGAME_H
#define WORDLEGAME_H

#include "../model/resources/Dictionary.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace Wordle
{

class WordleGame
{
public:
    WordleGame(int wordLength);
    virtual ~WordleGame();
    void makeGuess(string guess);

protected:

private:
    Dictionary* dictionary = new Dictionary();;
    int wordLength;
    const char* wordToBeGuessed;
    void playerGuess(string guess);
    void generateWord(vector<string> &words);
    int numberOfGuesses = 6;

};
}

#endif // WORDLEGAME_H
