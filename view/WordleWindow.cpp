#include "WordleWindow.h"

#include "../model/WordleGame.h"
#include "../model/resources/Dictionary.h"
using namespace Wordle;

namespace view {
WordleWindow::WordleWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    activeNumber = 0;
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
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            //this only does the first 24 letters of the aplhabet in buttons, because 26 doesn't divide cleanly except into 13, i can fix that when the stack smashing is fixed.
            int offset = q;
            //cout << q << endl;
            string label = this->qwertyAlphabet[q];
            this->keyboardSortingLabels[q] = new string(label);
            this->keyboardButton[25] = new Fl_Button(110 + (x * 30), 530 + (y * 30), 30, 30, keyboardSortingLabels[q]->c_str());
            this->keyboardButton[25]->callback(cbButton, this);
            q++;
        }
    }
    this->keyboardButton[25] = new Fl_Button(110 + (2 * 30), 530 + (4 * 30), 30, 30, "N");
    this->keyboardButton[25] = new Fl_Button(110 + (3 * 30), 530 + (4 * 30), 30, 30, "M");
    this->activeInput = this->wordleInput[activeNumber];
    //this->sortingRadioGroup->end();
}

void WordleWindow::cbButton(Fl_Widget* widget, void* data)
{
    WordleWindow* window = (WordleWindow*)data;
    Fl_Button* button = (Fl_Button*) widget;
    cout << button->label() <<endl;
    const char* jim = button->label();
    window->activeInput->value(jim);
    window->activeNumber++;
    window->activeInput = window->wordleInput[window->activeNumber];
}
}

