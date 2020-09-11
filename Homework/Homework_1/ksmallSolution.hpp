#ifndef KSMALL_SOLUTION_HPP
#define KSMALL_SOLUTION_HPP

#include "arrayTracker.hpp"

class ksmallSolution
{
private:
public:
  ksmallSolution();

  void arraySwap(arrayTracker* swappingArray, int indexA, int indexB);
  int kSmallPartition(arrayTracker* unsortedArray);
};
#endif /* KSMALL_SOLUTION_HPP */