#include "LinkedSortedList.hpp"
#include <iostream>
#include <string>

using namespace std;

Node<Player>* LinkedSortedList<Player>::copyChain( const Node<Player>* origChainPtr)
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