#include "WordleWindow.h"

#include "../model/WordleGame.h"

using namespace Wordle;

namespace view {
WordleWindow::WordleWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    int n = 0;
    for (int i=0; i<6; i++)
    {
        for (int j = 0; j<5; j++)
        {
            int offset = n;

            this->wordleInput[offset] = new Fl_Input(110 + (j*60), 20 + (i*60), 45, 45, "");
            this->wordleInput[offset]->type(FL_INPUT_TYPE);
            //this->wordleInput[offset]->callback(cbTextEntered, this);
            n++;
        }
    }
    createKeyboard();

    Dictionary* words = new Dictionary();
    words->Debug();
    WordleGame* game = new WordleGame(5);
    game->makeGuess("Somer");
    end();
}

WordleWindow::~WordleWindow()
{
    //dtor
}

void WordleWindow::createKeyboard()
{
    //this->sortingRadioGroup = new Fl_Group(100,100,1000,1000);
    //this->sortingRadioGroup->begin();
    int q = 0;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            //this only does the first 24 letters of the aplhabet in buttons, because 26 doesn't divide cleanly except into 13, i can fix that when the stack smashing is fixed.
            int offset = q;
            cout << q << endl;
            string label = this->qwertyAlphabet[q];
            this->keyboardSortingLabels[q] = new string(label);
            this->keyboardButton[25] = new Fl_Button(110 + (y * 30), 530 + (x * 30), 30, 30, keyboardSortingLabels[q]->c_str());
            q++;
        }
    }
    //this->sortingRadioGroup->end();
}
}

