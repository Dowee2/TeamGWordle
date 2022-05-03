#include "PlayerStatistics.h"
#include <sstream>

namespace model
{
PlayerStatistics::PlayerStatistics()
{
    //ctor
}

PlayerStatistics::~PlayerStatistics()
{
    //dtor
}

void PlayerStatistics::gameLost()
{
    this->streak = 0;
    this->playedGame();
}

void PlayerStatistics::gameWon(int guesses)
{
    this->incrementGuessDistribution(guesses);
    this->incrementStreak();
    this->playedGame();
}

int PlayerStatistics::getWinRate()
{
    int wins = 0;
    for(auto const& win : this->guessDistributon)
    {
        wins += win.second;
    }
    return (wins/this->gamesPlayed)*100;
}

string PlayerStatistics::toString()
{
    stringstream output;
    output<< this->gamesPlayed << ", "
          << this->streak << ", "
          << this->highestStreak;

    for(auto const& win : this->guessDistributon)
    {
        output << ", " << win.second;
    }
    return output.str();
}
}
