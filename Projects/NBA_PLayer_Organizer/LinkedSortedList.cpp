#include "LinkedSortedList.hpp"
#include <iostream>
#include <string>

using namespace std;

Node<Player>* LinkedSortedList<Player>::getNodeBefore(const Player& anEntry) const {
  Node<Player>* curPtr = headPtr;
  Node<Player>* prevPtr = nullptr;

  while ((curPtr != nullptr) && (anEntry > curPtr->getItem())) {
    prevPtr = curPtr;
    curPtr = curPtr->getNext();
  } // end while

  return prevPtr;
} // end getNodeBefore 

Node<Player>* LinkedSortedList<Player>::copyChain(const Node<Player>* origChainPtr)
{
  Node<Player>* copiedChainPtr;
  if (origChainPtr == nullptr) {
    copiedChainPtr = nullptr;
    itemCount = 0;
  }
  else {
    // Build new chain from given one
    Node<Player>* copiedChainPtr = new Node<Player>(origChainPtr->getItem());
    copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    itemCount++;
  } // end if
  
  return copiedChainPtr;
} // end copyChain 

LinkedSortedList<Player>::LinkedSortedList() {
}

LinkedSortedList<Player>::LinkedSortedList(const LinkedSortedList<Player>& aList) {
  headPtr = copyChain(aList.headPtr); 
}

void LinkedSortedList<Player>::insertSorted(const Player& newEntry)
{
  Node<Player>* newNodePtr = new Node<Player>(newEntry);
  Node<Player>* prevPtr = getNodeBefore(newEntry);

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

