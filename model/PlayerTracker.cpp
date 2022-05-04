#include "PlayerTracker.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Utils.h"

namespace model
{
PlayerTracker::PlayerTracker(string playerName)
{
    this->loadPlayers();
    this->setCurrentPlayer(playerName);
    this->savePlayers();
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

void PlayerTracker::savePlayers()
{
    fstream fout;
    fout.open(this->savefile,ios::out);

    for(auto const& player : this->players)
    {
        fout << player.first << ", " << player.second->toString() <<"\n";
    }
}

void PlayerTracker::loadPlayers()
{
    fstream fin;
    fin.open(this->savefile, ios::in);
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
        this->buildPlayers(content);
    }
    else
    {
        cout<<"Could not open the file\n";
    }
}

void PlayerTracker::buildPlayers(vector<vector<string>> content)
{
    for(int i=0; i<content.size(); i++)
    {
        string playerName = content[i][0];
        int gamesPlayed = toInt(content[i][1], "Error converting games played to an integer.");
        int streak = toInt(content[i][2], "Error converting winning streak to an integer.");
        int highestStreak = toInt(content[i][3], "Error converting highest win streak to an integer.");
        int oneGuesses = toInt(content[i][4], "Error converting one guess games to an integer.");
        int twoGuesses = toInt(content[i][5], "Error converting two guess games to an integer.");
        int threeGuesses = toInt(content[i][6], "Error converting three guess games to an integer.");
        int fourGuesses = toInt(content[i][7], "Error converting four guess games to an integer.");
        int fiveGuesses = toInt(content[i][8], "Error converting five guess games to an integer.");
        int sixGuesses = toInt(content[i][9], "Error converting six guess games to an integer.");
        std::map<const int,int> guessDistributon = {{1,oneGuesses}, {2,twoGuesses}, {3,threeGuesses}, {4,fourGuesses}, {5,fiveGuesses}, {6,sixGuesses}};

        PlayerStatistics* stats = new PlayerStatistics(gamesPlayed,streak,highestStreak,guessDistributon);

        this->players.insert(std::pair<string, PlayerStatistics*>(playerName, stats));
        cout << stats->toString() << endl;
    }
}
}
