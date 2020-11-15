#include "LinkedSortedList.hpp"
#include <iostream>
#include <string>

using namespace std;

Node<Player>* LinkedSortedList<Player>::getNodeBefore(const string& playerName) const {
  Node<Player>* curPtr = headPtr;
  Node<Player>* prevPtr = nullptr;

  while ((curPtr != nullptr) && (playerName > curPtr->getPlayerName())) {
    prevPtr = curPtr;
    curPtr = curPtr->getNext();
  } // end while

  return prevPtr;
} // end getNodeBefore 

Node<Player>* LinkedSortedList<Player>::getNodeAt(int position) const {
  // Debugging check of precondition
  assert((position >= 1) &&(position <= itemCount));
  // Count from the beginning of the chain
  Node<Player>* curPtr = headPtr;
  for (int skip = 1; skip < position; skip++) {
    curPtr = curPtr->getNext();
  }
    
  return curPtr ;  
} // end getNodeAt

Node<Player>* LinkedSortedList<Player>::copyChain(const Node<Player>* origChainPtr)
{
  Node<Player>* copiedChainPtr;
  if (origChainPtr == nullptr) {
    copiedChainPtr = nullptr;
    itemCount = 0;
  }
  else {
    // Build new chain from given one
    Node<Player>* copiedChainPtr = new Node<Player>(origChainPtr->getPlayerName(), origChainPtr->getPlayerTeam(), origChainPtr->getPlayerPointsPerGame(), origChainPtr->getPlayerReboundsPerGame(), origChainPtr->getPlayerAssistsPerGame());
    copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    itemCount++;
  } // end if
  
  return copiedChainPtr;
} // end copyChain 

LinkedSortedList<Player>::LinkedSortedList() : headPtr(nullptr), itemCount(0) {
} // end default constructor 

LinkedSortedList<Player>::~LinkedList() {
  clear();
} // end destructor 

LinkedSortedList<Player>::LinkedSortedList(const LinkedSortedList<Player>& aList) {
  headPtr = copyChain(aList.headPtr); 
} // end copy constructor

void LinkedSortedList<Player>::insertSorted(const string& player, const string& teamName, const int pointsPerGame, const int reboundsPerGame, const int assistsPerGame) {
  Node<Player>* newNodePtr = new Node<Player>(player, teamName, pointsPerGame, reboundPerGame, assistsPerGame);
  Node<Player>* prevPtr = getNodeBefore(player);

  if (isEmpty() || (prevPtr == nullptr)) { //add at beginning
    newNodePtr->setNext(headPtr);
    headPtr = newNodePtr;
  }
  else { // Add after node before
    Node<Player>* aftPtr = prevPtr->getNext();
    newNodePtr->setNext(aftPtr);
    prevPtr->setNext(newNodePtr);
  } // end if

  itemCount++;
} // end insertSorted 

bool LinkedSortedList<Player>::removeSorted(const string& player) {
  return remove(getPositionOfPlayer(player));
} // end removeSorted

int LinkedSortedList<Player>::getPositionOfPlayer(const string& player) {
  for(int position = 1; position <= getLength(); position++) {
    if((getEntry(position)->getName()) == player) {
      return position;
    }
  }
  return -1;
} // end getPositionOfPlayer

bool LinkedSortedList<Player>::isEmpty() const {
  return headPtr == nullptr;
} // end isEmpty 

int LinkedSortedList<Player>::getLength() const {
  return itemcount;
} // end getLength

bool LinkedSortedList<Player>::remove(int position) {
  bool ableToRemove = (position >= 1) &&(position <= itemCount);
  if (ableToRemove) {
    Node<Player>* curPtr = nullptr;
    if (position == 1) {
      // Remove the first node in the chain
      curPtr = headPtr; // Save pointer to node
      headPtr = headPtr->getNext();
    }
    else {
      // Find node that is before the one to delete
      Node<Player>* prevPtr = getNodeAt(position - 1);
      // Point to node to delete
      curPtr = prevPtr->getNext();
      // Disconnect indicated node from chain by connecting the
      // prior node with the one after
      prevPtr->setNext(curPtr->getNext());
    } // end else

    // Return node to system
    curPtr->setNext( nullptr); 

    delete curPtr;
    curPtr = nullptr;

    itemCount–-; // Decrease count of entries
  } // end if

  return ableToRemove;
} // end remove 

void LinkedSortedList<Player>::clear() {
  while (!isEmpty()){
    remove(1);
  }  
} // end clear 

Player LinkedSortedList<Player>::getEntry(int position) const throw(PrecondViolatedExcep) {
  // Enforce precondition
  bool ableToGet = (position >= 1) &&(position <= itemCount);
  if (ableToGet) {
    Node<Player>* nodePtr = getNodeAt(position);
    return nodePtr->getPlayer();
  }
  else {
    string message = "getEntry() called with an empty list or ";
    message = message + "invalid position.";
    throw(PrecondViolatedExcep(message));
  } // end if
} // end getEntry 

