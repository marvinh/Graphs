#ifndef QUEUE_H
#define QUEUE_H
#include "Stack.h"

class Queue{
public:
    Queue();
    ~Queue();
    bool empty();
    int size();
    int front();
    void push(int i);
    void pop();
private:
    Stack in;
    Stack out;
    int numberOfEntries;
};

Queue::Queue(){
    numberOfEntries = 0;
}

Queue::~Queue(){

}

bool Queue::empty(){
    return in.empty()&&out.empty();
}

int Queue::size(){
    return numberOfEntries;
}

int Queue::front(){
   if(out.empty()){
       while(!in.empty()){
           out.push(in.top());
           in.pop();
       }
   }
   return out.top();
}

void Queue::push(int i){
    in.push(i);
    numberOfEntries++;
}

void Queue::pop(){
    if(out.empty()){
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
    out.pop();
    numberOfEntries--;
}

#endif // QUEUE_H
