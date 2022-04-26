#ifndef GUESSCHECKER_H
#define GUESSCHECKER_H

#include <vector>
using namespace std;

enum LetterPlacement {CORRECT, CONTAINS, WRONG};
vector<LetterPlacement> checkGuess(const char* guess, const char* word,int wordLength);


#endif // GUESSCHECKER_H
