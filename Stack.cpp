#include "Stack.h"
#include <cstddef>
#include <iostream>
#include <sstream>
using namespace std;

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
  while (!isEmpty()) {
    pop();
  }
}

void Stack::push(int newData) {
  Node *newNode = new Node();
  newNode->data = newData;
  newNode->next = top;
  top = newNode;
}

int Stack::pop() {
  if (isEmpty()) {
    return -1;
  } else {
    Node *temp = top;
    int data = temp->data;
    top = top->next;
    delete temp;
    return data;
  }
}

int Stack::peek() const {
  if (isEmpty()) {
    return -1;
  } else {
    return top->data;
  }
}

bool Stack::isEmpty() const {
  if (top == NULL) {
    return true;
  } else {
    return false;
  }
}

void Stack::display() {
  Node *curr = top;
  while (curr != NULL) {
    cout << curr->data << " ";
    curr = curr->next;
  }

  cout << " | ";
}

string Stack::displayToString() {
  stringstream ss;
  Node *curr = top;
  while (curr != NULL) {
    ss << curr->data << " ";
    curr = curr->next;
  }
  return ss.str();
}