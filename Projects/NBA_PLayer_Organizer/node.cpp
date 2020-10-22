#include "Node.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;

Node<Player>::Node() : next(nullptr) {
} // end default constructor


Node<Player>::Node(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame) : name(playerName), teamName(playerTeamName), pointsPerGame(playerPointsPerGame), reboundsPerGame(playerReboundsPerGame), assistsPerGame(playerAssistsPerGame), next(nullptr) {
} // end constructor

Node<Player>::Node(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame, Node<Player>* nextNodePtr) : name(playerName), teamName(playerTeamName), pointsPerGame(playerPointsPerGame), reboundsPerGame(playerReboundsPerGame), assistsPerGame(playerAssistsPerGame), next(nextNodePtr) { 
} // end constructor
 
void Node<Player>::setPlayerName(const string& playerName) {
  nodePlayer->setName(playerName);
} // end setPlayerName

void Node<Player>::setPlayerTeamName(const string& playerTeamName) {
  nodePlayer->setTeamName(playerTeamName);
} // end setPlayerTeamName

void Node<Player>::setPlayerPointsPerGame(const int& playerPointsPerGame) {
  nodePlayer->setPointsPerGame(playerPointsPerGame);
} // end setPlayerPointsPerGame

void Node<Player>::setPlayerReboundsPerGame(const int& playerReboundsPerGame) {
  nodePlayer->setReboundsPerGame(playerReboundsPerGame);
} // end setPlayerReboundsPerGame

void Node<Player>::setPlayerAssistsPerGame(const int& playerAssistsPerGame) {
  nodePlayer->setAssistsPerGame(playerAssistsPerGame);
} // end setPlayerAssistsPerGame
 
void Node<Player>::setNext(Node<Player>* nextNodePtr)
{
 next = nextNodePtr;
} // end setNext
 
string Node<Player>::getPlayerName() const
{
 return nodePlayer->getName();
} // end getPlayerName

string Node<Player>::getPlayerTeamName() const
{
 return nodePlayer->getTeamName();
} // end getPlayerTeamName

int Node<Player>::getPlayerPoitsPerGame() const
{
 return nodePlayer->getPointsPerGame();
} // end getPlayerPointsPerGame

int Node<Player>::getPlayerReboundsPerGame() const
{
 return nodePlayer->getReboundsPerGame();
} // end getPlayerReboundsPerGame

int Node<Player>::getPlayerAssistsPerGame() const
{
 return nodePlayer->getAssistsPerGame();
} // end getPlayerAssistsPerGame
 
Node<Player>* Node<Player>::getNext() const
{
 return next;
} // end getNext 