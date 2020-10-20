#include <iostream>

using namespace std;

/*
g++ main.cpp -o midterm.exe
The function binarySearch accepts a sorted array data with no duplicates, 
and the range within that array to search, defined by first and last. 
Finally, goal is the value that is searched for within the array. 
If the goal can be found within the array, the function returns the 
index position of the goal value in the array. If the goal value does 
not exist in the array, the function returns -1.
*/
int binarySearch(int data[], int first, int last, int goal)
{
  cout << "first: " << first << ", last: " << last << endl;
  
  // YOU CAN ONLY ADD OR CHANGE CODE BELOW THIS COMMENT

  if(first > last) { 
    return -1;
  }
  else {
    int mid = first + (last - first) / 2;
    if(goal == data[mid]) {
      return mid; 
    }
    else if(goal < data[mid]) {
      return binarySearch(data, first, mid - 1, goal);
    }
    else {
      return binarySearch(data, mid + 1, last, goal);
    }
  }
  
  // YOU CAN ONLY ADD OR CHANGE CODE ABOVE THIS COMMENT
}

int main()
{
  const int ARRAY_SIZE = 20;
  int searchValue;
  
  /* generates an array data that contains:
    0, 10, 20, 30, .... 170, 180, 190
  */
  int data[ARRAY_SIZE]; 
  for(int i = 0; i < ARRAY_SIZE; i++)
    data[i] = i * 10;
  
  cout << "Enter Search Value: ";
  cin >> searchValue;
  int answer = binarySearch(data, 0, ARRAY_SIZE-1, searchValue);
  cout << "Answer: " << answer << endl;
  return 0;
}