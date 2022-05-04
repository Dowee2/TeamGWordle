#ifndef WORDLELOGINWINDOW_H
#define WORDLELOGINWINDOW_H

#include <FL/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_File_Chooser.H>

#include <string>
using namespace std;

namespace view
{
class WordleLoginWindow : public Fl_Window
{
public:
    /** Default constructor */
    WordleLoginWindow();
    /** Default destructor */
    virtual ~WordleLoginWindow();

    static void cbLogin(Fl_Widget* widget, void* data);
    void loginHandler();

    string getUsername() {return this->username;}
    int getWordLength(){return this->wordLength;}
    void determineWordlength();

protected:

private:
    Fl_Button* loginButton;
    Fl_Input* usernameInput;
    Fl_Choice* wordLengthInput;
    string username;
    void setwordLengthInput();
    int wordLength;
};
}

#endif // WORDLELOGINWINDOW_H
