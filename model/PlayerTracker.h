#ifndef PLAYERTRACKER_H
#define PLAYERTRACKER_H
#include "PlayerStatistics.h"
#include <vector>
#include <map>

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
        std::map<const string,PlayerStatistics*> getPlayers() { return players; }

        /** The current player in the game */
        PlayerStatistics* currentPlayer;

        /** Updates the current users statistics
         *
         */
        void updatePlayerStats(int guessesMade, int WinOrLose);

    protected:

    private:
        std::map<const string,PlayerStatistics*>players; //!< Member variable "players"
        void loadPlayers();
        void savePlayers();
        void setCurrentPlayer(string playerName);
        void buildPlayers(vector<vector<string>> content);
        string savefile = "model/resources/players.txt";
};
}

#endif // PLAYERTRACKER_H
