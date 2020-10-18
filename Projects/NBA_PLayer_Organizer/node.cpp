#include "node.hpp"
#include <iostream>
using namespace std;

Node<string>::Node() : next(nullptr) {
} // end default constructor


Node<string>::Node(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame) : name(playerName), teamName(playerTeamName), pointsPerGame(playerPointsPerGame), reboundsPerGame(playerReboundsPerGame), assistsPerGame(playerAssistsPerGame), next(nullptr)
{
} // end constructor

Node<ItemType>::Node(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame, Node<string>* nextNodePtr) : name(playerName), teamName(playerTeamName), pointsPerGame(playerPointsPerGame), reboundsPerGame(playerReboundsPerGame), assistsPerGame(playerAssistsPerGame), next(nextNodePtr)
{
} // end constructor
 
void Node<string>::setName(const string& playerName) {
 name = playerName;
} // end setName

void Node<string>::setTeamName(const string& playerTeamName) {
 teamName = playerTeamName;
} // end setTeamName

void Node<string>::setPointsPerGame(const int& playerPointsPerGame) {
 pointsPerGame = playerPointsPerGame;
} // end setPointsPerGame

void Node<string>::setReboundsPerGame(const int& playerReboundsPerGame) {
 reboundsPerGame = playerReboundsPerGame;
} // end setReboundsPerGame

void Node<string>::setAssistsPerGame(const int& playerAssistsPerGame) {
 assistsPerGame = playerAssistsPerGame;
} // end setAssistsPerGame
 
void Node<string>::setNext(Node<string>* nextNodePtr)
{
 next = nextNodePtr;
} // end setNext
 
string Node<string>::getName() const
{
 return name;
} // end getName

string Node<string>::getTeamName() const
{
 return teamName;
} // end getTeamName

int Node<string>::getPoitsPerGame() const
{
 return pointsPerGame;
} // end getPointsPerGame

int Node<string>::getReboundsPerGame() const
{
 return reboundPerGame;
} // end getReboundsPerGame

int Node<string>::getAssistsPerGame() const
{
 return assistsPerGame;
} // end getAssistsPerGame
 
Node<string>* Node<string>::getNext() const
{
 return next;
} // end getNext 