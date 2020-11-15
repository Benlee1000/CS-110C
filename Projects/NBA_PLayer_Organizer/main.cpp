#include "LinkedSortedList.hpp"

using namespace std;
// g++ main.cpp LinkedSortedList.cpp Node.cpp Player.cpp PrecondViolatedExcep.cpp

int main() {
  string playerName, playerTeam;
  int playerPPG, playerRPG, playerAPG;

  cout << "Welcome to the NBA PLayer Organizer" << endl;

  while (true) {
    LinkedSortedList playerList;
    cout << "Please enter a player name, 1 to stop: ";
    cin >> playerName;
    if (playerName == "1") {
      break;
    }
    cout << "Please enter the player's team: ";
    cin >> playerTeam; 
    cout << "Please enter the player's points per game: ";
    cin >> playerPPG;
    cout << "Please enter the player's rebounds per game: ";
    cin >> playerRPG;
    cout << "Please enter the player's rebounds per game: "
    cin >> playerAPG;
    cout << "\n";

    playerList->insertSorted(playerName, playerTeam, playerPPG, playerRPG, playerAPG);
  } 

  for (int index = 1; index <= playerList->getLength(); i++) {

    Player playerObj = playerList->getEntry(index);
    cout << playerObj->getName();
    cout << "Team: " << playerObj->getTeamName() << " PPG: " << playerObj->getPointsPerGame() << " RPG: " << playerObj->getReboundsPerGame() << " APG: " << playerObj->getAssistsPerGame() << "\n\n";
  }

}