#ifndef STACK_H
#define STACK_H
#include <stdio.h>

struct node{
    node(int i){
        item = i;
        next = NULL;
    }
    int item;
    node *next;
};

class Stack{
public:
    Stack();
    ~Stack();
    bool empty();
    int size();
    int top();
    void push(int i);
    void pop();
private:
    int numberOfEntries;
    node *head;
};

Stack::Stack(){
    head = NULL;
    numberOfEntries = 0;
}
Stack::~Stack(){
    while(head!=NULL){
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

bool Stack::empty(){
    return head==NULL;
}

int Stack::size(){
    return numberOfEntries;
}

int Stack::top(){
    return head->item;
}

void Stack::push(int i){
    node *temp = new node(i);
    temp->next = head;
    head = temp;
    numberOfEntries++;
}

void Stack::pop(){
    if(head!=NULL){
        node *temp = head;
        head = head->next;
        delete temp;
        numberOfEntries--;
    }
}

#endif // STACK_H
