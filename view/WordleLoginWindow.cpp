#include "WordleLoginWindow.h"
#include <Fl/fl_ask.H>
namespace view {

WordleLoginWindow::WordleLoginWindow() : Fl_Window(250, 150, "Login")
{
    begin();

    this->loginButton = new Fl_Button(100, 90, 70, 30, "Login");
    this->usernameInput = new Fl_Input(100, 35, 100, 25, "Username:");
    this->loginButton->callback(cbLogin, this);



    end();
}

void WordleLoginWindow::cbLogin(Fl_Widget* widget, void* data)
{
    WordleLoginWindow* window = (WordleLoginWindow*)data;
    window->loginHandler();
}
void WordleLoginWindow::loginHandler() {
    try
        {
            this->username = this->usernameInput->value();
            this->hide();
        }
        catch (const char* message)
        {
            fl_message("%s", message);
        }
}


WordleLoginWindow::~WordleLoginWindow()
{
    //dtor
}

}
