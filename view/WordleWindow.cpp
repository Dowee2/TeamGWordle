#include "WordleWindow.h"
#include "WordleLoginWindow.h"
#include "PlayerTracker.h"

#include "../model/WordleGame.h"
#include "../model/resources/Dictionary.h"
using namespace Wordle;
using namespace model;

namespace view {
// Constructor for the WordleWindow
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
            this->wordleInput[offset]->when(FL_WHEN_ENTER_KEY);
            this->wordleInput[offset]->callback(cbTextEntered, this);

            n++;
            this->wordleInput[offset]->deactivate();
        }
    }
    this->wordleInput[0]->activate();
    createKeyboard();

    Dictionary* words = new Dictionary();
    words->Debug();
    this->game = new WordleGame(5);
    WordleLoginWindow login;
    login.set_modal();
    login.show();

    while (login.shown())
    {
        Fl::wait();
    }

    PlayerTracker tracker = PlayerTracker(login.getUsername());
    end();
}

//Wordle window destrcutor
WordleWindow::~WordleWindow()
{
    //dtor
}

//Creates the keyboard for the wordle window.
void WordleWindow::createKeyboard()
{
    int q = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            int offset = q;
            //cout << q << endl;
            string label = this->qwertyAlphabet[q];
            this->keyboardSortingLabels[q] = new string(label);
            this->keyboardButton[25] = new Fl_Button(110 + (x * 30), 530 + (y * 30), 30, 30, keyboardSortingLabels[q]->c_str());
            this->keyboardButton[25]->callback(cbKeyboard, this);
            q++;
        }
    }
    this->keyboardButton[25] = new Fl_Button(110 + (2 * 30), 530 + (4 * 30), 30, 30, "N");
    this->keyboardButton[25]->callback(cbKeyboard, this);
    this->keyboardButton[25] = new Fl_Button(110 + (3 * 30), 530 + (4 * 30), 30, 30, "M");
    this->keyboardButton[25]->callback(cbKeyboard, this);
    this->activeInput = this->wordleInput[activeNumber];
    this->guessButton = new Fl_Button(110, 700, 180, 30, "Guess");
    this->guessButton->callback(cbGuess, this);
    //this->sortingRadioGroup->end();
}

//callback for entering text into the wordle window.
void WordleWindow::cbTextEntered(Fl_Widget* widget, void* data)
{
    WordleWindow* window = (WordleWindow*)data;
    Fl_Input* input = (Fl_Input*) widget;
     const char* jim = input->value();
     if (string(jim).length() > 1) {
           return;
     }
     cout << jim << endl;
    if (jim != "") {
        if (window->activeInput->active()) {
            window->activeInput->value(jim);
        }
        if (window->activeNumber < 29 && window->activeInput->active()) {
            window->activeNumber++;
        }
        window->activeInput->deactivate();
        window->activeInput = window->wordleInput[window->activeNumber];
        if (window->activeNumber != 5 && window->activeNumber != 10 && window->activeNumber != 15 && window->activeNumber != 20 && window->activeNumber != 25) {
            window->activeInput->activate();
            window->activeInput->take_focus();
        }
    }

}

//Call back for using the on screen keyboard.
void WordleWindow::cbKeyboard(Fl_Widget* widget, void* data)
{
    WordleWindow* window = (WordleWindow*)data;
    Fl_Button* button = (Fl_Button*) widget;
    cout << button->label() <<endl;
    const char* jim = button->label();
    if (window->activeInput->active()) {
        window->activeInput->value(jim);
    }
    if (window->activeNumber < 29 && window->activeInput->active()) {
        window->activeNumber++;
    }
    window->activeInput->deactivate();
    window->activeInput = window->wordleInput[window->activeNumber];
    if (window->activeNumber != 5 && window->activeNumber != 10 && window->activeNumber != 15 && window->activeNumber != 20 && window->activeNumber != 25) {
    window->activeInput->activate();
    window->activeInput->take_focus();
    }
}

//Callback for the guess button
void WordleWindow::cbGuess(Fl_Widget* widget, void* data)
{
    WordleWindow* window = (WordleWindow*)data;
    Fl_Button* button = (Fl_Button*) widget;
    Fl_Input** input = window->getInputs();
    WordleGame* myGame = window->getGame();
    int guesses = myGame->getNumberOfGuesses();

    string starter = "";
    if ((window->activeNumber == 5 || window->activeNumber == 10 || window->activeNumber == 15 || window->activeNumber == 20 || window->activeNumber == 25 || window->activeNumber == 29) && input[window->activeNumber - 5]->value() != "" && input[window->activeNumber - 4]->value() != "" && input[window->activeNumber - 3]->value() != "" && input[window->activeNumber - 2]->value() != "" && input[window->activeNumber - 1]->value() != "" && guesses > 1) {
        string output = starter + input[window->activeNumber - 5]->value() + input[window->activeNumber - 4]->value() + input[window->activeNumber - 3]->value() + input[window->activeNumber - 2]->value() + input[window->activeNumber - 1]->value();
        auto letterChecks = window->game->makeGuess(output);
        if (window->getGame()->getNumberOfGuesses() == 1) {
            window->activeNumber++;
        }
        if (letterChecks[0] == 0) {
            cout << "0 good" << endl;
            input[window->activeNumber - 5]->color(FL_DARK_GREEN);
            input[window->activeNumber - 5]->redraw();
        } else if (letterChecks[0] == 1) {
            input[window->activeNumber - 5]->color(FL_YELLOW);
            input[window->activeNumber - 5]->redraw();
        }
        if (letterChecks[1] == 0) {
            cout << "0 good" << endl;
            input[window->activeNumber - 4]->color(FL_DARK_GREEN);
            input[window->activeNumber - 4]->redraw();
        } else if (letterChecks[1] == 1) {
            input[window->activeNumber - 4]->color(FL_YELLOW);
            input[window->activeNumber - 4]->redraw();
        }
        if (letterChecks[2] == 0) {
            cout << "0 good" << endl;
            input[window->activeNumber - 3]->color(FL_DARK_GREEN);
            input[window->activeNumber - 3]->redraw();
        } else if (letterChecks[2] == 1) {
            input[window->activeNumber - 3]->color(FL_YELLOW);
            input[window->activeNumber - 3]->redraw();
        }
        if (letterChecks[3] == 0) {
            cout << "0 good" << endl;
            input[window->activeNumber - 2]->color(FL_DARK_GREEN);
            input[window->activeNumber - 2]->redraw();
        } else if (letterChecks[3] == 1) {
            input[window->activeNumber - 2]->color(FL_YELLOW);
            input[window->activeNumber - 2]->redraw();
        }
        if (letterChecks[4] == 0) {
            cout << "0 good" << endl;
            input[window->activeNumber - 1]->color(FL_DARK_GREEN);
            input[window->activeNumber - 1]->redraw();
        } else if (letterChecks[4] == 1) {
            input[window->activeNumber - 1]->color(FL_YELLOW);
            input[window->activeNumber - 1]->redraw();
        }
        if (window->getGame()->getNumberOfGuesses() == 1) {
            window->activeNumber--;
        }
            input[window->activeNumber]->activate();

    cout << output << endl;
    }
}

//gets the array of inputs from the window
Fl_Input** WordleWindow::getInputs(){
    return this->wordleInput;
}

//gets the wordle game from the window
WordleGame* WordleWindow::getGame(){
    return this->game;
}
}

