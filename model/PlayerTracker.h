#ifndef PLAYERTRACKER_H
#define PLAYERTRACKER_H
#include "Player.h"
#include <vector>

namespace model{
class PlayerTracker
{
    public:
        /** Default constructor */
        PlayerTracker(string playerName);
        /** Default destructor */
        virtual ~PlayerTracker();

        /** Access players
         * \return The current value of players
         */
        vector<Player> getPlayers() { return players; }

        /** The current player in the game */
        Player currentPlayer;

        /** Updates the current users statistics
         *
         */
        void updatePlayerStats(int guessesMade, int WinOrLose);

    protected:

    private:
        vector<Player> players; //!< Member variable "players"
        void loadPlayers(string filepath);
        void setCurrentPlayer(string playerName);
};
}

#endif // PLAYERTRACKER_H
