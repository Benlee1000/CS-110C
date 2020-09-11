#ifndef KSMALL_TESTER_HPP
#define KSMALL_TESTER_HPP

#include "arrayTracker.hpp"

class ksmallTester
{
private:
public:
  ksmallTester();
  int testPartition(arrayTracker* testSubject, int pivotIndex);
};
#endif /* KSMALL_TESTER_HPP */