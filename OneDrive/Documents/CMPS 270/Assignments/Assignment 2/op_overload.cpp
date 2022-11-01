//
// Created by Moustapha Ghandour on 11/1/2022.
//
#include"my_stack.h"
template <typename T>
my_stack<T> operator+ (my_stack <T> &a, my_stack <T> &b)
{
    my_stack <T> CopyElements;
    my_stack <T> c;
    while(!a.isEmpty())
    {
        CopyElements.push(a.top());
        a.pop();
    }
    while(!CopyElements.isEmpty())
    {
        c.push(CopyElements.top());
        a.push(CopyElements.top());
        CopyElements.pop();
    }

    while(!b.isEmpty())
    {
        CopyElements.push(b.top());
        b.pop();
    }
    while(!CopyElements.isEmpty())
    {
        c.push(CopyElements.top());
        b.push(CopyElements.top());
        CopyElements.pop();
    }

    return c;
}
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
    my_stack<int> q ;
    q.push(1);
    q.push(2);
    my_stack <int> w;
    w.push(3);
    w.push(5);
    my_stack <int> z = q + w;
    cout <<"Top: " << z.top() << endl;
    cout << "Size(z)= " << z.size() <<endl;
}
