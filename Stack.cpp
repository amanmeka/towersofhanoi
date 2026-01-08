#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while(!isEmpty) {
        pop();
    }
}

int Stack::pop() {

}

void Stack::push(int newData) {
    
}

void Stack::display() {
    
}