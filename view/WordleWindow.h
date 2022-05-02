#ifndef WORDLEWINDOW_H
#define WORDLEWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>
#include "../model/WordleGame.h"

#include "../model/resources/Dictionary.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;
using namespace Wordle;
namespace view
{
class WordleWindow : public Fl_Window
{
    public:
        WordleWindow(int width, int height, const char* title);
        virtual ~WordleWindow();
        Fl_Input* activeInput;
        int activeNumber;
        Fl_Input** getInputs();


    protected:

    private:
        Fl_Input* wordleInput[30];
        Fl_Button* keyboardButton[26];
        Fl_Button* guessButton;
        Fl_Group *sortingRadioGroup;
        vector<string> qwertyAlphabet = {"Q", "W", "E" ,"R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X","C", "V", "B", "N", "M"};
        string* keyboardSortingLabels[26];
        static void cbTextChanged(Fl_Widget* widget, void* data);
        static void cbKeyboard(Fl_Widget* widget, void* data);
        static void cbGuess(Fl_Widget* widget, void* data);
        void createKeyboard();
        WordleGame* game;


};
}
#endif // WORDLEWINDOW_H
