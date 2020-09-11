#ifndef KSMALL_TESTER_CPP
#define KSMALL_TESTER_CPP

#include "ksmallTester.hpp"

ksmallTester::ksmallTester() {
}

int ksmallTester::testPartition(arrayTracker* testSubject, int pivotIndex)
{
  int result = testSubject->getUseCount();
  for(int i=0; i<testSubject->getSize(); i++)
  {
    if(i<pivotIndex) // test S1
      if(testSubject->getItem(i) >= testSubject->getItem(pivotIndex))
        result = -1;
    if(i>pivotIndex) // test S2
      if(testSubject->getItem(i) < testSubject->getItem(pivotIndex))
        result = -1;
  }
  return result;
}

#endif /* KSMALL_TESTER_CPP */