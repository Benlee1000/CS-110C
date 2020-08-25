/*
 * This program calculates the number n in a fibonacci sequence
 * using recursion
 */

#include <iostream>

using namespace std;

int findFibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    return findFibonacci(n-2) + findFibonacci(n-1);
}

int main() {
    int fibNum;
    int finalNum;

    cout << "Enter a number, -1 to quit: ";
    cin >> fibNum;

    while (fibNum != 1) {
        
        finalNum = findFibonacci(fibNum);
        cout << "The " << fibNum << " number of the fibonacci sequence is " << finalNum << endl;
        cout << "Enter a number, -1 to quit: ";
        cin >> fibNum;
    }
}


