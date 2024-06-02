#pragma once
#include "Vector.h" 
#include "Stack.h"//#include "Vector.h"         //homework targil 2 !
//-------------------------------------------------------
//  class StackVector
//  Stack implemented using Vector
//  Vector will grow as necessary to avoid overflow
//-------------------------------------------------------
template <class T>
class StackVector : public Stack {
public:
    // constructor requires a starting size
    StackVector(unsigned int capacity);
    StackVector(const StackVector<T>& s);
    // Stack operations
    void clear() override;
    bool isEmpty() const override;
    int pop() override;
    void push(int value) override;
    int top() const override;

protected:
    // data fields
    Vector<T> data;
};
#include "StackVector.h"

//-------------------------------------------------------
//  class StackVector implementation
//-------------------------------------------------------
template <class T> 
StackVector<T>::StackVector(unsigned int capacity) : data(capacity)
{
    // create and initialize a Stack based on Vectors
}

template <class T>
StackVector<T>::StackVector(const StackVector& s): data(s.data)
{ /* copy constructor*/
}
template <class T>
void StackVector<T>::clear()
{
    // clear all elements from Stack, by setting
    // index to bottom of Stack
    data.clear();
}
template <class T>
bool StackVector<T>::isEmpty() const
{
    return data.getSize() == 0;
}
template <class T>
int StackVector<T>::pop()
{
    // return and remove the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data.delLast();
}



template <class T>
void StackVector<T>::push(int val)
{
    // push new value onto Stack
    data.insert(val);
}
template <class T>
int StackVector<T>::top() const
{
    // return the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data[data.getSize() - 1];
}
