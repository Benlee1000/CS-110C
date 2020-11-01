#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "SortedListInterface.hpp"
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"
#include "Player.hpp"
#include <iostream>


class LinkedSortedList : public SortedListInterface<Player> {
private:
  Node<Player>* headPtr; // Pointer to first node in the chain
  int itemCount; // Current count of list items

 // Locates the node that is before the node that should or does
 // contain the given entry.
 // @param anEntry The entry to find.
 // @return Either a pointer to the node before the node that contains
 // or should contain the given entry, or nullptr if no prior node exists.
  Node<Player>* getNodeBefore(const string& playerName) const;

  // Locates the node at a given position within the chain.
  Node<Player>* getNodeAt(int position) const;

  // Returns a pointer to a copy of the chain to which origChainPtr points.
  Node<Player>* copyChain(const Node<Player>* origChainPtr);

public:
  LinkedSortedList();
  LinkedSortedList(const LinkedSortedList<Player>& aList);
  virtual ~LinkedSortedList(); 
  void insertSorted(const string& player, const string& teamName, const int pointsPerGame, const int reboundsPerGame, const int assistsPerGame);
  bool removeSorted(const string& player);
  int getPositionOfPlayer(const string& player) const;
  bool isEmpty() const;
  int getLength() const;
  bool remove(int position);
  void clear();
  Player getEntry(int position) const throw(PrecondViolatedExcep);
}; // end LinkedSortedList

#endif