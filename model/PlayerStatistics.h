#ifndef PLAYER_H
#define PLAYER_H
#include <map>

using namespace std;

namespace model
{
class PlayerStatistics
{
public:
    /** Default constructor */
    PlayerStatistics();
    PlayerStatistics(int gamesPlayed, int streak, int highestStreak,std::map<const int,int> guessdistribution);
    /** Default destructor */
    virtual ~PlayerStatistics();

    /** Gets the amount of games played by user
     * \return The current value of gamesPlayed
     */
    int getGamesPlayed()
    {
        return gamesPlayed;
    }

    /** Increments players current number of games played by one
     */
    void playedGame()
    {
        gamesPlayed++;
    }
    /** Gets the players current streak
     * \return The current value of streak
     */
    int getStreak()
    {
        return streak;
    }

    /** Increments players current streak by one
     */
    void incrementStreak()
    {
        streak++;
    }


    /** Gets the players highest streak achieved
     * \return highestStreak The highest streak the plays has obtained
     */
    int getHighestStreak()
    {
        return highestStreak;
    }


    /** Gets the players guess distributon
     * \return The current value of distributon
     */
    std::map<const int,int> getGuessDistributon()
    {
        return guessDistributon;
    }

    /** Updates player statistics for a game loss
     * \param guesses The amount of guesses it toke to solve the puzzle
     */
    void gameLost();

    /** Updates player statistics for a game win
     * \param guesses The amount of guesses it toke to solve the puzzle
     */

    void gameWon(int guesses);

    /** Gets the player's win rate
     * \return int The players winrate
     */

    int getWinRate();

    /** A String representation of the players statistics
     * \return string A String holding all player statistics
     */

    string toString();
protected:

private:
    void incrementGuessDistribution(int guesses)
    {
        this->guessDistributon.at(guesses)++;
    }
    int gamesPlayed; //!< Member variable "gamesPlayed"
    int streak; //!< Member variable "streak"
    int highestStreak; //!< Member variable "highestStreak"
    std::map<const int,int> guessDistributon; //!< Member variable "guessDistributon"
};
}

#endif // PLAYER_H
