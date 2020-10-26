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

LinkedSortedList<Player>::LinkedSortedList() : headPtr(nullptr), itemCount(0) {
} // end default constructor 

LinkedSortedList<Player>::~LinkedList() {
  clear();
} // end destructor 

LinkedSortedList<Player>::LinkedSortedList(const LinkedSortedList<Player>& aList) {
  headPtr = copyChain(aList.headPtr); 
} // end copy constructor

void LinkedSortedList<Player>::insertSorted(const Player& newEntry) {
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
bool LinkedStack<Player>::isEmpty() const {
  return headPtr == nullptr;
} // end isEmpty 

int LinkedStack<Player>::getLength() const {
  return itemcount;
}

bool LinkedSortedList<PLayer>::remove(int position) {
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

