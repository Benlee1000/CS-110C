#ifndef STUDENT_SOLUTION_CPP
#define STUDENT_SOLUTION_CPP
#include <iostream>
#include <stack>
#include "studentSolution.hpp"
using namespace std;

bool isPalindromeStack(char* word){
	bool returnValue = true;
  stack<char> myStack; 
  int i = 0;

  int wordLength = 0;
	while(word[wordLength] != '\0'){
    wordLength++;
  }

  // copy first half of word into the stack
	while (i < wordLength / 2) {
    myStack.push(word[i]);
    // cout << word[i] << "\n";
    i++;
  }

  // skip middle letter if word is an odd number of characters
  if (wordLength % 2 != 0) {
    i++;
  }

  // compare values stored in the stack with those in the end of the character array
  while (i < wordLength) {
    // cout << word[i] << "\n";
    if (word[i] != myStack.top()) {
      returnValue = false; // if letters don't match up, word is not a palindrome
    }
    //remove last letter checked from stack and go to next letter in the array
    myStack.pop();
    i++;
  }
	return returnValue;
}
#endif /* STUDENT_SOLUTION_CPP */