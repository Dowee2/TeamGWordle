#ifndef WORDLEGAME_H
#define WORDLEGAME_H

#include "Dictionary.h"
using namespace std;

namespace Wordle{

class WordleGame
{
    public:
        WordleGame(int wordLength);
        virtual ~WordleGame();


    protected:

    private:
        Dictionary* dictionary = new Dictionary();;
        int wordLength;
        const char* wordToBeGuessed;
        void playerGuess(string guess);
        void generateWord(vector<string> &words);

};
}

#endif // WORDLEGAME_H
