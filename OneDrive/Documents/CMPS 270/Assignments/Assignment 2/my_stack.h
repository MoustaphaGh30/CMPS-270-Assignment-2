//
// Created by mosta on 11/1/2022.
//

#ifndef ASSIGNMENT_2_MY_STACK_H
#define ASSIGNMENT_2_MY_STACK_H
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class my_stack {
private:
    std:: vector <T> List;
public:
    int size ()
    {
        return List.size();
    }

    bool isEmpty()
    {
        if(List.size() == 0)
            return true;
        return false;
    }

    void push (T item)
    {
        List.push_back(item);
    }

    T &top ()
    {
        if(isEmpty())
        {
            throw invalid_argument("Stack is empty\n");
        }
        T  &copy = List[List.size()-1];
        return copy;
    }

    void pop() {
        if (!isEmpty())
            List.pop_back();
        else
            cout<<"Stack is Empty!";
    }

};


#endif //ASSIGNMENT_2_MY_STACK_H
