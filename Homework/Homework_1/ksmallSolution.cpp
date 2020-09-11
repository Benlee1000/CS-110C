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
  int i = 1;
  cout << "Array before sorting: \n";
  unsortedArray->displayArray();

  while(i < unsortedArray->getSize()) {
    
    //if a value in the array is smaller than the pivot value, and comes after it in the array, swap them
    if((unsortedArray->getItem(i) < pivotValue) && (i > pivotIndex)) {
      this->arraySwap(unsortedArray, i, pivotIndex);
      pivotIndex = i;
      i = 0; //go back to beginning of array
      //cout << "array after less pivot:\n"; 
      //unsortedArray->displayArray();
      
    }

    //else if a value in the array is larger than the pivot value, and comes before the array, swap them 
    else if((unsortedArray->getItem(i) >= pivotValue ) && (i < pivotIndex)) {
      this->arraySwap(unsortedArray, i, pivotIndex);
      pivotIndex = i;
      i = 0; //go back to begining of array
      //cout << "array after more pivot:\n"; 
      //unsortedArray->displayArray();
    }
    i++; //increment through the array if there are no numbers out of place
    
  }
  cout << "Array after sorting: \n";
  unsortedArray->displayArray();
  
  return 0;
}

#endif /* KSMALL_SOLUTION_CPP */