#ifndef KSMALL_SOLUTION_CPP
#define KSMALL_SOLUTION_CPP

#include <iostream>
#include "ksmallSolution.hpp"
#include "arrayTracker.hpp"

using namespace std;

ksmallSolution::ksmallSolution() {
}

void ksmallSolution::arraySwap(arrayTracker* swappingArray, int indexA, int indexB)
{
  int temp = swappingArray->getItem(indexA);
  swappingArray->setItem(indexA, swappingArray->getItem(indexB));
  swappingArray->setItem(indexB, temp);
}


int ksmallSolution::kSmallPartition(arrayTracker* unsortedArray)
{
	int pivotValue = unsortedArray->getItem(0);
  int pivotIndex = 0;
  int temp;
  // cout << "Array before sorting: \n";
  // unsortedArray->displayArray();

  // increment through array, starting at position after the intial pivot index
  for(int i = 1; i < unsortedArray->getSize(); i++) {
    // if an item is smaller, store it in temp
    // then move all values before that to the right using the swap method
    if(unsortedArray->getItem(i) < pivotValue) {
      temp = unsortedArray->getItem(i);
      for(int j = i; j > pivotIndex; j--) {
        this->arraySwap(unsortedArray, j, j-1);
      }
      // place temp in right before the pivot value and increase the pivot index
      unsortedArray->setItem(pivotIndex, temp);
      pivotIndex++;
    }
  }
  // cout << "Array after sorting: \n";
  // unsortedArray->displayArray();

  
  return pivotIndex;
}

#endif /* KSMALL_SOLUTION_CPP */