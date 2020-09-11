#ifndef ARRAY_TRACKER_HPP
#define ARRAY_TRACKER_HPP

const int MAX_ARRAY_SIZE = 10000;

class arrayTracker
{
private:
  int items[MAX_ARRAY_SIZE];
  int useCount;
  int arraySize;
  unsigned receipt;

public:
  arrayTracker();
  arrayTracker(int newSize);
  arrayTracker(int newSize, int seedValue);

  int getUseCount();
  
  int getItem(int itemIdx);
  bool setItem(int itemIdx, int itemValue);
  int getSize();
  void displayArray();
};

#endif /*ARRAY_TRACKER_HPP*/