#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "WordleWindow.h"
using namespace view;
int main (int argc, char ** argv)
{
   WordleWindow mainWindow(1000, 800, "TeamG : A4");
   mainWindow.show();
   int exitCode = Fl::run();
   return exitCode;
}
