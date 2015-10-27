//
//  Graph.h
//  Graph
//
//  Created by marvin h on 10/26/15.
//  Copyright © 2015 marvin h. All rights reserved.
//

#ifndef Graph_h
#define Graph_h
#include "Stack.h"
template <typename T>
class Graph{
public:
    /*
     Basic Graph class. Includes functions to add edge,
     add verticies, dfs traversal, and a print of the graph.
     */
    //define a init size for the table to begin with
    Graph(int size);
    ~Graph();
    //add edge to verticie include vertecie key and data
    void addEdge(int v,int key,T data);
    //add edge to verticie include vertecie key
    void addEdge(int v,int key);
    //add how ever many new verticies
    void addVertcies(int addV);
    //dfs traversal
    void dfs(int v);
    
    void print();
private:
    //need to reset visited array
    //and find disconnects
    void dfsUtil(int v);
    int* visited;
    int tableSize;
    SinglyLinkedList<T>* table;
};
template <typename T>
Graph<T>::Graph(int size){
    if(size>0){
        tableSize=size;
    }
    else{
        tableSize=1;
    }
    visited = new int[tableSize];
    for(int i=0;i<tableSize;i++){
        visited[i]=0;
    }
    table = new SinglyLinkedList<T>[tableSize]();
}
template <typename T>
Graph<T>::~Graph(){
    tableSize=0;
    delete [] visited;
    delete [] table;
}
template <typename T>
void Graph<T>::addEdge(int v,int key,T data){
    //assert(v>-1&&v<tableSize&&key>-1&&key<tableSize);
    if((v>-1&&v<tableSize)&&(key>-1&&key<tableSize)){
        table[v].insert(key,data);
    }else{
        std::cout<<"invalid arguments\n";
    }
}
template <typename T>
void Graph<T>::addEdge(int v,int key){
    //assert(v>-1&&v<tableSize&&key>-1&&key<tableSize);
    if((v>-1&&v<tableSize)&&(key>-1&&key<tableSize)){
        table[v].insert(key);
    }else{
        std::cout<<"invalid arguments\n";
    }
}
template <typename T>
void Graph<T>::addVertcies(int addv){
    int orginalSize = tableSize;
    tableSize=tableSize+addv;
    
    delete [] visited;
    visited = new int[tableSize];
    
    SinglyLinkedList<T>* tempTable = new SinglyLinkedList<T>[tableSize]();
    for(int i = 0; i<orginalSize;i++){
        visited[i]=0;
        tempTable[i].operator=(table[i]);
    }
    //shallow copy tempTable
    delete [] table;
    table = tempTable;
}
template <typename T>
void Graph<T>::dfsUtil(int v){
    Stack<T> S;
    S.push(v);
    while(!S.empty()){
        //pop returns a new node/container
        //which needs to be deleted
        Node<T>* temp = S.pop();
        v = temp->_key;
        delete temp;
        if(visited[v]!=1){
            visited[v]=1;
            std::cout<<v<<" ";
            Node<T>* walker = table[v].front();
            while(walker!=NULL){
                S.push(walker->_key);
                walker=walker->_next;
            }
        }
    }
    for(int i = 0;i < tableSize ; i++){
        if(visited[i]!=1){
            dfsUtil(i);
        }
    }
}
template <typename T>
void Graph<T>::dfs(int v){
    dfsUtil(v);
    for(int i=0;i<tableSize;i++){
        visited[i]=0;
    }
}
template<typename T>
void Graph<T>::print(){
    for (int v=0; v<tableSize; v++) {
        std::cout<<"[["<<v<<"]->";
        table[v].print();
        std::cout<<"]\n";
    }
    
}
#endif /* Graph_h */
