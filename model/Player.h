#ifndef PLAYER_H
#define PLAYER_H
#include <map>

using namespace std;

namespace model{
class Player
{
    public:
        /** Default constructor */
        Player();
        /** Default destructor */
        virtual ~Player();

        /** Access gamesPlayed
         * \return The current value of gamesPlayed
         */
        int GetGamesPlayed() { return gamesPlayed; }

        /** Increments players current number of games played by one
         */
        void playedGame() { gamesPlayed++; }
        /** Access streak
         * \return The current value of streak
         */
        int getStreak() { return streak; }

        /** Increments players current streak by one
         */
        void incrementStreak() { streak++; }


        /** Access highestStreak
         * \return highestStreak The highest streak the plays has obtained
         */
        int getHighestStreak() { return highestStreak; }


        /** Access distributon
         * \return The current value of distributon
         */
        std::map<const int,int> getDistributon() { return distributon;}

        /** Increments the  by one
         *
         * \param guesses The number of guesses toke to solve the puzzle
         */

        void incrementGuessDistribution(int guesses) {this->distributon.at(guesses)++;}
    protected:

    private:
        int gamesPlayed = 0; //!< Member variable "gamesPlayed"
        int streak = 0; //!< Member variable "streak"
        int highestStreak = 0; //!< Member variable "highestStreak"
        std::map<const int,int> distributon = {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}}; //!< Member variable "distributon"
};
}

#endif // PLAYER_H
