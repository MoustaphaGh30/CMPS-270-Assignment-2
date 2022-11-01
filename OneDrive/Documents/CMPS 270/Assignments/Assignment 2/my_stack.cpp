//
// Created by Moustapha Ghandour on 11/1/2022.
//

/*
    int size ()
    Requires: Nothing
    Effects: returns the size of the stack
_________________________________________________________________________________________________

    bool isEmpty()
    Requires: Nothing
    Effects: returns true if the stack is empty, false otherwise.
_________________________________________________________________________________________________

    T *top ()
    Requires: Nothing.
    Effects: Returns the value of the last added element, and if empty throws an error saying so.
    Testing Strategy:
    _Empty Stack
_________________________________________________________________________________________________
    void pop()
    Requires: Nothing.
    Effects: Deletes the last element in the stack, if it is empty then print a statement saying so.
_________________________________________________________________________________________________
    *     void push (T *item)
    Requires: Nothing.
    Effects:  adds a pointer to item to the stack.
_________________________________________________________________________________________________
*/

#include <iostream>
#include <vector>
#include "my_stack.h"
using namespace std;
int main() {
    my_stack<int> Stack;
    int a=1;
    int b=2;
    int c=3;
    Stack.push(a);
    Stack.push(b);
    Stack.push(c);
    cout << "Top:" << Stack.top() << "\n";
    cout << "Size= " << Stack.size() << "\n";
    Stack.pop();
    cout << "Size after popping: " << Stack.top() << "\n";
}