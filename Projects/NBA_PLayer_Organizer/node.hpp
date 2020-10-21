#ifndef _NODE
#define _NODE

#include <string>

class Node {
private:   
  string playerName; 
  string  playerTeamName;
  int pointsPerGame;
  int reboundPerGame;
  int assistsPerGame;
  Node<string>* next; // Pointer to next node
public:
  Node();
  Node(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame);
  Node(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame, Node<string>* nextNodePtr);
  void setName(const string& playerName);
  void setTeam(const string&  playerTeamName);
  void setPointsPerGame(cont int& playerPointsPerGame);
  void setReboundsPerGame(cont int& playerReboundsPerGame);
  void setAssistsPerGame(cont int& playerAssistsPerGame);
  void setNext(Node<string>* nextNodePtr);
  string getName() const;
  string getTeam() const;
  int getPointsPerGame() const;
  int getReboundsPerGame() const;
  int getAssistsPerGame() const;
  Node<string>* getNext() const;
}; // end Node

#include "node.cpp"
#endif 