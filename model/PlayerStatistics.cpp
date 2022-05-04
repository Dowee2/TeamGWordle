#include "PlayerStatistics.h"
#include <sstream>

namespace model
{
PlayerStatistics::PlayerStatistics()
{
    this->gamesPlayed = 0;
    this->streak = 0;
    this->highestStreak = 0;
    this->guessDistributon = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}};
}

PlayerStatistics::PlayerStatistics(int gamesPlayed, int streak, int highestStreak,std::map<const int,int> guessdistribution)
{
    this->gamesPlayed = gamesPlayed;
    this->streak = streak;
    this->highestStreak = highestStreak;
    this->guessDistributon = guessdistribution;
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
    return (wins)*100/this->gamesPlayed;
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
