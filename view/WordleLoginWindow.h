#ifndef WORDLELOGINWINDOW_H
#define WORDLELOGINWINDOW_H

#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Input.H>

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

    void setLoginLocation(int x, int y);

    static void cbLogin(Fl_Widget* widget, void* data);
    void loginHandler();

    string getUsername() {return this->username;}

protected:

private:
    Fl_Button* loginButton;
    Fl_Input* usernameInput;
    string username;
};
}

#endif // WORDLELOGINWINDOW_H
