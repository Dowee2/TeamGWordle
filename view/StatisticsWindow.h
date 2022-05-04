#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <FL/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <FL/Fl_Chart.H>
#include <FL/Fl_Text_Display.H>

#include "PlayerStatistics.h"

using namespace model;

namespace view
{

class StatisticsWindow : public Fl_Window
{
public:
    /** Default constructor */
    StatisticsWindow(PlayerStatistics* player);
    /** Default destructor */
    virtual ~StatisticsWindow();

    /** Access currentPlayer
     * \return The current value of currentPlayer
     */
    PlayerStatistics* getCurrentPlayer()
    {
        return currentPlayer;
    }



protected:

private:
    PlayerStatistics* currentPlayer; //!< Member variable "currentPlayer"
    void populateChart();
    void populateStatistics();
    Fl_Chart* statsChart;
    Fl_Text_Display* played = new Fl_Text_Display(40,20,30,30,"Games Played");
    Fl_Text_Display* winRate = new Fl_Text_Display(160,20,30,30,"Win Rate");
    Fl_Text_Display* streak = new Fl_Text_Display(280,20,30,30,"Current Streak");
    Fl_Text_Display* maxStreak = new Fl_Text_Display(400,20,30,30,"Max Streak");
};
}

#endif // STATISTICSWINDOW_H
