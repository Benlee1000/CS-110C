#ifndef _NODE
#define _NODE

#include <string>

class Node {
private:   
  Player* nodePlayer;
  Node<Player>* next; // Pointer to next node
public:
  Node();
  Node(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame);
  Node(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame, Node<Player>* nextNodePtr);
  void setPlayerName(const string& playerName);
  void setPlayerTeam(const string&  playerTeamName);
  void setPlayerPointsPerGame(cont int& playerPointsPerGame);
  void setPlayerReboundsPerGame(cont int& playerReboundsPerGame);
  void setPlayerAssistsPerGame(cont int& playerAssistsPerGame);
  void setNext(Node<Player>* nextNodePtr);
  string getPlayerName() const;
  string getPlayerTeam() const;
  int getPlayerPointsPerGame() const;
  int getPlayerReboundsPerGame() const;
  int getPlayerAssistsPerGame() const;
  Node<Player>* getNext() const;
}; // end Node


#endif 