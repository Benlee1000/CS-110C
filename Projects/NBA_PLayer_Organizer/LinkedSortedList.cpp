#include "LinkedSortedList.hpp"
#include <iostream>
#include <string>

using namespace std;

Node<string>* LinkedSortedList<string>::copyChain( const Node<string>* origChainPtr)
{
  Node<string>* copiedChainPtr;
  if (origChainPtr == nullptr) {
    copiedChainPtr = nullptr;
    itemCount = 0;
  }
  else {
    // Build new chain from given one
    Node<string>* copiedChainPtr = new Node<string>(origChainPtr->getItem());
    copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    itemCount++;
  } // end if
  
  return copiedChainPtr;
} // end copyChain 

LinkedSortedList<string>::LinkedSortedList() {
}

LinkedSortedList<string>::LinkedSortedList(const LinkedSortedList<string>& aList) {
  headPtr = copyChain(aList.headPtr); 
}