//
//  Stack.h
//  Graph
//
//  Created by marvin h on 10/26/15.
//  Copyright © 2015 marvin h. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include "SinglyLinkedList.h"
template <typename T>
class Stack{
public:
    /*
     Stack class. Pop and Top return nodes because
     I have several types of data in that container
     */
    Stack();
    ~Stack();
    Node<T>* pop();
    Node<T>* top();
    void push(int key, T data);
    void push(int key);
    bool empty();
private:
    SinglyLinkedList<T> s;
};
template <typename T>
Stack<T>::Stack(){}

template <typename T>
Stack<T>::~Stack(){}

template <typename T>
void Stack<T>::push(int key, T data){s.insert(key,data);}

template <typename T>
void Stack<T>::push(int key){s.insert(key);}

template <typename T>
Node<T>* Stack<T>::pop(){
    Node<T>* popped = new Node<T>(top()->_key,top()->_data);
    s.remove();
    return popped;
}

template <typename T>
Node<T>* Stack<T>::top(){return s.front();}

template <typename T>
bool Stack<T>::empty(){return s.empty();}

#endif /* Stack_h */
