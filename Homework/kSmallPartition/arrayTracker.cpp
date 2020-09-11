#ifndef ARRAY_TRACKER_CPP
#define ARRAY_TRACKER_CPP

#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include "arrayTracker.hpp"


using namespace std;

arrayTracker::arrayTracker() {
  useCount = 0;
}

arrayTracker::arrayTracker(int newSize) {
  useCount = 0;
  receipt = (unsigned) time(0);
  srand(receipt);
  for(int i = 0; i < newSize; i++) {
    items[i] = rand()%newSize;
  }
  arraySize = newSize;
}

arrayTracker::arrayTracker(int newSize, int seedValue) {
  useCount = 0;
  receipt = seedValue;
  srand(receipt);
  for(int i = 0; i < newSize; i++) {
    items[i] = rand()%newSize;
  }
  arraySize = newSize;
}

int arrayTracker::getUseCount() {
  return useCount;
}

int arrayTracker::getItem(int itemIdx) {
  if(itemIdx < 0 || itemIdx >= arraySize) {
    cout << "ERROR: unrecognized index value: " << itemIdx << endl;
    return 0;
  } 
  useCount++;
  return items[itemIdx];
}

bool arrayTracker::setItem(int itemIdx, int itemValue) {
  if(itemIdx < 0 || itemIdx >= arraySize) {
    cout << "ERROR: unrecognized index value: " << itemIdx << endl;
    return false;
  } 
  useCount++;
  items[itemIdx] = itemValue;
  return true;
}

int arrayTracker::getSize() {
  return arraySize;
}

void arrayTracker::displayArray()
{
  for(int i=0; i<arraySize; i++)
    cout << right << setfill('0') << setw(3) << i << " ";
  cout << endl;
  
  for(int i=0; i<arraySize; i++)
    cout << setfill(' ')<< right << setw(3) << items[i] << " ";
  cout << endl;
}

#endif /*ARRAY_TRACKER_CPP*/