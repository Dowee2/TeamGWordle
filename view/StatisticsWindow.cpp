#include "StatisticsWindow.h"
#include <FL/fl_draw.H>
#include <iostream>

using namespace std;
namespace view
{

StatisticsWindow::StatisticsWindow(PlayerStatistics* player) : Fl_Window(500, 500, "Statistics")
{
    begin();
    this->currentPlayer = player;
    this->statsChart = new Fl_Chart(50,250,350,200,"Guess Distribution");
    this->statsChart->type(1);
    this->populateChart();
    this->statsChart->autosize(1);
    this->played->buffer(new Fl_Text_Buffer());
    this->winRate->buffer(new Fl_Text_Buffer());
    this->streak->buffer(new Fl_Text_Buffer());
    this->maxStreak->buffer(new Fl_Text_Buffer());
    this->populateStatistics();
    end();
}

void StatisticsWindow::populateChart()
{
    for(auto const& guess : this->currentPlayer->getGuessDistributon())
    {
        string label =  to_string(guess.first);
        this->statsChart->add(guess.second,label.c_str(),85);
    }
}

void StatisticsWindow::populateStatistics()
{
    this->played->buffer()->text(to_string(this->currentPlayer->getGamesPlayed()).c_str());
    this->winRate->buffer()->text(to_string(this->currentPlayer->getWinRate()).c_str());
    this->streak->buffer()->text(to_string(this->currentPlayer->getStreak()).c_str());
    this->maxStreak->buffer()->text(to_string(this->currentPlayer->getHighestStreak()).c_str());

}

StatisticsWindow::~StatisticsWindow()
{
    //dtor
}
}
