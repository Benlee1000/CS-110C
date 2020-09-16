#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include "arrayTracker.hpp"
#include "ksmallSolution.hpp"
#include "ksmallTester.hpp"
#include "ksmallRuleChecker.hpp"

// compile together:
// g++ main.cpp arrayTracker.cpp ksmallRuleChecker.cpp ksmallSolution.cpp ksmallTester.cpp -o ksmallPartition.exe

using namespace std;

int main() {
  ksmallSolution temp;
  ksmallTester tester;
	ksmallRuleChecker checkRules;

	if(checkRules.checkString("ksmallSolution.cpp", "vector") != -1) {
		cout << "vector found\n";
	}
	if(checkRules.checkString("ksmallSolution.cpp", "[") != -1) {
		cout << "array found\n";
	} 

  int testCaseSize = 10;
  int testCaseRuns = 10;
  int value;
  int kValue = 10;
  
  //int score;
  //int scoreAverage = 0;

  for(int i=0; i<testCaseRuns; i++) {
    arrayTracker* test;
    test = new arrayTracker(testCaseSize, i+1);
    value = temp.kSmall(kValue, test, 0, testCaseSize);
    cout << "The "<< kValue << "th smallest value in the array is: " << value << "\n\n";
    delete test;
  }

  // for(int i=0; i<testCaseRuns; i++) {
  //   arrayTracker* test;
  //   test = new arrayTracker(testCaseSize, i+1);
  //   score = tester.testPartition(test, temp.kSmallPartition(test));
  //   if (score>=0)
  //     scoreAverage += score/testCaseRuns;
  //   else
  //     cout << "fail" << '\n';
  //   delete test;
  // }
  // cout << "par avg score: " << scoreAverage << '\n';
}
