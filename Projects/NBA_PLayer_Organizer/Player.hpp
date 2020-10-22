#ifndef _Player
#define _Player

#include <string>

class Player {
private:
  string name; 
  string teamName;
  int pointsPerGame;
  int reboundPerGame;
  int assistsPerGame;

public:
  player();
  player(const string& playerName, const string& playerTeamName, const int& playerPointsPerGame, const int& playerReboundsPerGame, const int& playerAssistsPerGame);
  void setName(const string& playerName);
  void setTeamName(const string&  playerTeamName);
  void setPointsPerGame(cont int& playerPointsPerGame);
  void setReboundsPerGame(cont int& playerReboundsPerGame);
  void setAssistsPerGame(cont int& playerAssistsPerGame);
  string getName() const;
  string getTeamName() const;
  int getPointsPerGame() const;
  int getReboundsPerGame() const;
  int getAssistsPerGame() const;
};
#endif