#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <map>

using namespace std;

class Dictionary
{
    public:
        /** Default constructor */
        Dictionary();
        /** Default destructor */
        virtual ~Dictionary();


        vector<string> getAllWordsOfLength(int wordlength);


        void Debug();

    protected:

    private:
        void generateVocabulary();
        void addWord(string& word);
        std::map<const int, vector<string>> vocabulary;

};

#endif // DICTIONARY_H
