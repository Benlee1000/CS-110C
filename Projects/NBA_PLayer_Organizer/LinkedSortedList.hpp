#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "SortedListInterface.hpp"
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"
#include <string>


class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
  Node<string>* headPtr; // Pointer to first node in the chain
  int itemCount; // Current count of list items

 // Locates the node that is before the node that should or does
 // contain the given entry.
 // @param anEntry The entry to find.
 // @return Either a pointer to the node before the node that contains
 // or should contain the given entry, or nullptr if no prior node exists.
  Node<string>* getNodeBefore( const string& anEntry) const;

  // Locates the node at a given position within the chain.
  Node<string>* getNodeAt( int position) const;

  // Returns a pointer to a copy of the chain to which origChainPtr points.
  Node<string>* copyChain( const Node<string>* origChainPtr);

public:
  LinkedSortedList();
  LinkedSortedList(const LinkedSortedList<string>& aList);
  virtual ~LinkedSortedList(); 