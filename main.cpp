#include "Stack.h"
#include <iomanip>
#include <iostream>
using namespace std;

Stack towerA, towerB, towerC;

// FORMATTING
string toString(Stack &tower) { return tower.displayToString(); }

// FORMATTING
void displayTowers(Stack &tower1, Stack &tower2, Stack &tower3) {
  cout << "Tower A: " << setw(15) << left << toString(tower1)
       << " | Tower B: " << setw(15) << left << toString(tower2)
       << " | Tower C: " << setw(15) << left << toString(tower3) << endl;
}

void solveTowersOfHanoi(int n, Stack &tower1, Stack &tower2, Stack &tower3) {
  if (n == 0) {
    return;
  }
  solveTowersOfHanoi(n - 1, tower1, tower3, tower2);

  int disk = tower1.pop();
  tower3.push(disk);

  displayTowers(towerA, towerB, towerC);

  solveTowersOfHanoi(n - 1, tower2, tower1, tower3);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 0) {
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod
       << endl;
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// * * * * * * * * * * * * * * * * * * * * * * *
// Use this main.
int main() {
  int n; // Number of disks
  cout << "Enter the number of disks: ";
  cin >> n;
  if (n <= 0) {
    cout << "Number of disks must be greater than 0." << endl;
    return 1;
  }
  cout << "Steps to solve the Towers of Hanoi:" << endl;

  for (int i = 0; i < n; i++) {
    towerA.push(n - i);
  }

  cout << "Initial:" << endl;
  displayTowers(towerA, towerB, towerC);
  cout << endl;

  solveTowersOfHanoi(n, towerA, towerB, towerC);
  return 0;
}
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
