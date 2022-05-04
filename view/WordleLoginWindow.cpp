#include "WordleLoginWindow.h"
#include <Fl/fl_ask.H>

namespace view
{

WordleLoginWindow::WordleLoginWindow() : Fl_Window(250, 150, "Login")
{
    begin();

    this->loginButton = new Fl_Button(100, 100, 70, 30, "Login");
    this->usernameInput = new Fl_Input(100, 35, 100, 25, "Username:");
    this->loginButton->callback(cbLogin, this);
    this->wordLengthInput = new Fl_Choice(100, 70, 50, 25, "Word Length:");
    this->setwordLengthInput();
    end();
}

void WordleLoginWindow::cbLogin(Fl_Widget* widget, void* data)
{
    WordleLoginWindow* window = (WordleLoginWindow*)data;
    window->loginHandler();
}
void WordleLoginWindow::loginHandler()
{
    try
    {
        if(this->usernameInput->value() != NULL)
        {
            this->username = this->usernameInput->value();
            this->determineWordlength();
            this->hide();
        } else {
            Fl::error("Please enter a username");
        }

    }
    catch (const char* message)
    {
        fl_message("%s", message);
    }
}

void WordleLoginWindow::setwordLengthInput()
{
    wordLengthInput ->add("3");
    wordLengthInput ->add("4");
    wordLengthInput ->add("5");
    wordLengthInput ->add("6");
    wordLengthInput ->add("7");
    wordLengthInput ->add("8");
    wordLengthInput ->value(2);
}

void WordleLoginWindow::determineWordlength() {
    int length = this->wordLengthInput->value();

    if(length == 0) {
        this->wordLength = 3;
    } else if (length == 1) {
        this->wordLength = 4;
    } else if (length == 2) {
        this->wordLength = 5;
    } else if (length == 3) {
        this->wordLength = 6;
    } else if (length == 4) {
        this->wordLength = 7;
    } else {
        this->wordLength = 8;
    }
}

WordleLoginWindow::~WordleLoginWindow()
{
    //dtor
}

}
