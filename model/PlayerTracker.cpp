#include "PlayerTracker.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <Utils.h>
namespace model
{
PlayerTracker::PlayerTracker(string playerName)
{
    this->setCurrentPlayer(playerName);
}

PlayerTracker::~PlayerTracker()
{
    //dtor
}

void PlayerTracker::setCurrentPlayer(string playerName)
{

    if(this->players.find(playerName) != this->players.end())
    {
        this->currentPlayer = this->players.at(playerName);
    }
    else
    {
        PlayerStatistics* stats = new PlayerStatistics();
        this->players.insert(std::pair<string, PlayerStatistics*>(playerName, stats));
        this->currentPlayer = this->players.at(playerName);
    }
}

void PlayerTracker::updatePlayerStats(int guessesMade,int WinOrLose)
{
    if(WinOrLose == 1)
    {
        this->currentPlayer->gameWon(guessesMade);
    }
    else
    {
        this->currentPlayer->gameLost();
    }
}

void PlayerTracker::loadPlayers()
{
    fstream fin;
    fin.open("model/resources/players.txt", ios::in);
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    if(fin.is_open())
    {
        while(getline(fin, line))
        {
            row.clear();
            stringstream str(line);

            while(getline(str, word, ','))
            {
                row.push_back(word);
            }
            content.push_back(row);
        }
    }
    else
    {
        cout<<"Could not open the file\n";
    }


}

void PlayerTracker::buildPlayers(vector<vector<string>> content) {
 for(int i=0; i<content.size(); i++)
    {
        int gamesPlayed = toInt(content[i][1], "Error converting year to an integer.");
        int lastName = toInt(content[i][2], "Error converting year to an integer.");
        int highestStreak = toInt(content[i][3], "Error converting year to an integer.");
        int oneGuesses = toInt(content[i][4], "Error converting year to an integer.");
        int twoGuesses = toInt(content[i][5], "Error converting year to an integer.");
        int threeGuesses = toInt(content[i][6], "Error converting year to an integer.");
        int fourGuesses = toInt(content[i][7], "Error converting year to an integer.");
        int fiveGuesses = toInt(content[i][8], "Error converting year to an integer.");
        int sixGuesses = toInt(content[i][9], "Error converting year to an integer.");
        std::map<const int,int> guessDistributon = {{1,oneGuesses}, {2,twoGuesses}, {3,threeGuesses}, {4,fourGuesses}, {5,fiveGuesses}, {6,sixGuesses}};


        PlayerStatistics`
        cout << "Before: " << window->cards->getlength() <<endl;
        window->cards->push(newCard);
        cout << "After: "<< window->cards->getlength() <<endl;

        cout<<"\n";
    }
}
}
