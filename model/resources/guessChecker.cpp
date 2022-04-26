#include "guessChecker.h"


vector<LetterPlacement> checkGuess(const char* guess, const char* word, int wordLength)
{
    vector<LetterPlacement> checked;
    for(unsigned int i = 0; i < wordLength; i++)
    {
        checked.push_back(LetterPlacement::WRONG);
        for(unsigned int j = 0; j < wordLength; j++)
        {
            if(guess[i] == word[j])
            {
                if(i != j)
                {
                    if(checked[i] == LetterPlacement::CORRECT )
                    {
                        checked[i] = LetterPlacement::CONTAINS;
                    }
                    break;
                }
                else
                {
                    if(guess[i] == word[j])
                    {
                        checked[i] = LetterPlacement::CORRECT;
                        break;
                    }
                }
            }
        }
    }
    return checked;
}
