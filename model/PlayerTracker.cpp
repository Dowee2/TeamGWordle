#include "PlayerTracker.h"

namespace model {
PlayerTracker::PlayerTracker(string playerName)
{
    this->setCurrentPlayer(playerName);
}

PlayerTracker::~PlayerTracker()
{
    //dtor
}

void PlayerTracker::setCurrentPlayer(string playerName) {
        if(this->players.at(playerName) != this->player.end());
}
}
