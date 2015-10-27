//
//  SinglyLinkedList.h
//  Graph
//
//  Created by marvin h on 10/26/15.
//  Copyright © 2015 marvin h. All rights reserved.
//

#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h
#include "Node.h"
//#include <assert.h>
template <typename T>
class SinglyLinkedList{
public:
    /*
     Basic SinglyLinkedList will only insert at head and remove from head
     .Includes function to get the front of the list, empty(),and a print function.
     */
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T>& RHS);
                                    //right hand side
    SinglyLinkedList& operator=(const SinglyLinkedList& RHS);
    ~SinglyLinkedList();
    void insert(int key,T data);
    void insert(int key);
    void remove();
    bool empty();
    void print();
    Node<T>* front();
private:
    void removeAll(){
        while (head!=NULL){
            this->remove();
        }
    }
    void copy(const SinglyLinkedList<T>& RHS){
        //edge case for lists in same address
        if(head!=RHS.front()){
            this->removeAll;
            Node<T> walker = RHS->front();
            while (walker!=NULL) {
                this->insert(walker->front()->_data,walker->front()->_key);
                walker=walker->_next;
            }
        }
    }
    Node<T>* head;
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList():head(NULL){
    
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& RHS){copy(RHS);}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& RHS){
    copy(RHS);
    return *this;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
    removeAll();
}

template<typename T>
Node<T>* SinglyLinkedList<T>::front(){
    return head;
}

template<typename T>
void SinglyLinkedList<T>::insert(int key,T data){
    Node<T>* temp=new Node<T>(key,data);
    temp->_next=head;
    head=temp;
}

template<typename T>
void SinglyLinkedList<T>::insert(int key){
    Node<T>* temp=new Node<T>(key,NULL);
    temp->_next=head;
    head= temp;
}

template<typename T>
void SinglyLinkedList<T>::remove(){
    if(head!=NULL){
        Node<T>* nodeToDelete = head;
        head=head->_next;
        delete nodeToDelete;
        nodeToDelete=NULL;
    }
}
template<typename T>
bool SinglyLinkedList<T>::empty(){
    return head==NULL;
}
template<typename T>
void SinglyLinkedList<T>::print(){
    Node<T>* walker=head;
    while (walker!=NULL) {
        //overloaded << in Node struct
        std::cout<<*walker;
        walker=walker->_next;
    }
    //null symbol
    std::cout<<"///";
}

#endif /* SinglyLinkedList_h */