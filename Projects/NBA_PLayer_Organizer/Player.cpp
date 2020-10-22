#include "Player.hpp"
#include <iostream>

using namespace std;

Player::player() {
} // end default constructor


Player::player(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame) : name(playerName), teamName(playerTeamName), pointsPerGame(playerPointsPerGame), reboundsPerGame(playerReboundsPerGame), assistsPerGame(playerAssistsPerGame) {
} // end constructor

 
void Player::setName(const string& playerName) {
 name = playerName;
} // end setName

void Player::setTeamName(const string& playerTeamName) {
 teamName = playerTeamName;
} // end setTeamName

void Player::setPointsPerGame(const int& playerPointsPerGame) {
 pointsPerGame = playerPointsPerGame;
} // end setPointsPerGame

void Player::setReboundsPerGame(const int& playerReboundsPerGame) {
 reboundsPerGame = playerReboundsPerGame;
} // end setReboundsPerGame

void Player::setAssistsPerGame(const int& playerAssistsPerGame) {
 assistsPerGame = playerAssistsPerGame;
} // end setAssistsPerGame
 

string Player::getName() const
{
 return name;
} // end getName

string Player::getTeamName() const
{
 return teamName;
} // end getTeamName

int Player::getPoitsPerGame() const
{
 return pointsPerGame;
} // end getPointsPerGame

int Player::getReboundsPerGame() const
{
 return reboundPerGame;
} // end getReboundsPerGame

int Player::getAssistsPerGame() const
{
 return assistsPerGame;
} // end getAssistsPerGame
