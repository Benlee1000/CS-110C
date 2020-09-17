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


int ksmallSolution::kSmallPartition(arrayTracker* unsortedArray, int first, int last)
{

	int pivotValue = unsortedArray->getItem(first);
  int pivotIndex = first;
  int temp;
  // cout << "Array before sorting: \n";
  // unsortedArray->displayArray();

  // increment through array, starting at position after the intial pivot index
  for(int i = first + 1; i <= last; i++) {
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

int ksmallSolution::kSmall(int k, arrayTracker* unsortedArray, int first, int last)
{
  // unsortedArray->displayArray();
  // cout << first << " "<< last << "\n";
  int pivotIndex = this->kSmallPartition(unsortedArray, first, last);
  int pivotValue = unsortedArray->getItem(pivotIndex);

  if (k < pivotIndex - first + 1) {
    return kSmall(k, unsortedArray, first, pivotIndex - 1);
  }
  else if (k == pivotIndex - first + 1) {
    cout << "Final array: \n";
    unsortedArray->displayArray();
    return pivotValue;
  } 
  else {
    return kSmall(k - (pivotIndex - first + 1), unsortedArray, pivotIndex + 1, last); 
  }
    
}

#endif /* KSMALL_SOLUTION_CPP */