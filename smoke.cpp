#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
  Stack myStack;
  myStack.push(10);
  myStack.push(20);
  myStack.push(30);
  cout << "Top element: " << myStack.peek() << endl; // Outputs 30
  myStack.pop();
  myStack.display(); // Displays: 20 10
  return 0;
}