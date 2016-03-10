#ifndef GRAPH_H
#define GRAPH_H
#include "Stack.h"
#include "Queue.h"
#include "MinPriorityQueue.h"
#include <iostream>
using namespace std;
#define INFINITY 100000

class Graph{
public:
    Graph(int size, bool direct);
    ~Graph();
    void addEdge(int i,int j, int weight);
    void dfsUtil(int v);
    void dfs(int v);
    void bfsUtil(int v);
    void bfs(int v);
    void dijkstraRun(int src, int finish);
    void mstPrim(int root);
    void print();
private:
    bool directed;
    int graphSize;
    int *visited;
    int *distance;
    int *key;
    int *predecessor;
    int **adjacenyMatrix;
};

Graph::Graph(int size, bool direct){
    directed = direct;
    graphSize = size;
    visited = new int[graphSize];
    distance = new int[graphSize];
    key = new int[graphSize];
    predecessor = new int[graphSize];
    adjacenyMatrix = new int*[graphSize];
    for(int i=0;i<graphSize;i++){
        visited[i]= -1;
        distance[i] = INFINITY;
        key[i] = INFINITY;
        predecessor[i] = -1;
        adjacenyMatrix[i] = new int[graphSize];
        for(int j=0;j<graphSize;j++){
            adjacenyMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph(){
    delete [] visited;
    delete [] predecessor;
    delete [] key;
    delete [] distance;
    for(int i=0;i<graphSize;i++){
        delete [] adjacenyMatrix[i];
    }
    delete [] adjacenyMatrix;
}

void Graph::addEdge(int i,int j, int weight){
    if(i>-1&&i<graphSize&&j>-1&&j<graphSize&&weight>0){
        adjacenyMatrix[i][j] = weight;
        if(directed == false){
            adjacenyMatrix[j][i] = weight;
        }
    }else{
        cout<<"error out of bounds or invalid weight"<<endl;
    }
}
void Graph::dfs(int v){
    for(int i=0;i<graphSize;i++){
        visited[i]=-1;
    }
    cout<<"dfs: ";
    for (int i = 0; i < graphSize; i++) {
        if(visited[i]==-1){
            dfsUtil(i);
        }
    }
    cout<<endl;
}

void Graph::dfsUtil(int v){
    Stack s;
    visited[v]=1;
    s.push(v);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        cout<<u<<" ";
        for(int v=0;v<graphSize;v++){
            if(adjacenyMatrix[u][v]>0&&visited[v]==-1){
                s.push(v);
                visited[v]=0;
            }
        }
        visited[u]=1;
    }
}

void Graph::bfs(int v){
    for(int i=0;i<graphSize;i++){
        visited[i]=-1;
    }
    cout<<"bfs: ";
    for (int i = 0; i < graphSize; i++) {
        if(visited[i]==-1){
            bfsUtil(i);
        }
    }
    cout<<endl;
}

void Graph::bfsUtil(int v){
    Queue q;
    visited[v]=1;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v=0;v<graphSize;v++){
            if(adjacenyMatrix[u][v]>0&&visited[v]==-1){
                q.push(v);
                visited[v]=0;
            }
        }
        visited[u]=1;
    }
    cout<<endl;
}

void Graph::dijkstraRun(int src, int finish){
    for(int i=0;i<graphSize;i++){
        distance[i] = INFINITY;
        predecessor[i] = -1;
    }
    MinPriorityQueue q;
    Stack s;
    distance[src] = 0;
    q.insert(distance[src],src);
    bool done = false;
    while(!q.empty()&&!done){
        MinPriorityQueueNode n = q.extractMin();
        int u = n.pos;
        if(u==finish){
            done = true;
        }
        for(int v=0;v<graphSize;v++){
            if(adjacenyMatrix[u][v]>0){
                int alt = distance[u] + adjacenyMatrix[u][v];
                if(alt<distance[v]){
                    distance[v] = alt;
                    q.insert(distance[v],v);
                    predecessor[v] = u;
                }
            }
        }
    }
    s.push(finish);
    int vertex = finish;

    while(predecessor[vertex]!=-1){
        vertex = predecessor[vertex];
        s.push(vertex);
    }

    cout<<"Dijkstra's shortest path: ";
    while(!s.empty()){
        cout<<"["<<s.top()<<"] ";
        s.pop();
    }
    cout<<"distance: "<<distance[finish]<<endl;
}

void Graph::mstPrim(int root){
    MinPriorityQueue q;
    key[root]=0;
    q.insert(key[root],root);
    visited[root]=1;
    for(int i=1;i<graphSize;i++){
        key[i] = INFINITY;
        predecessor[i] = -1;
        visited[i] = -1;
    }
    while(!q.empty()){
        MinPriorityQueueNode n = q.extractMin();
        int u = n.pos;
        for(int v=0;v<graphSize;v++){
            if(visited[v]==-1&&adjacenyMatrix[u][v]>0&&adjacenyMatrix[u][v]<key[v]){
                predecessor[v] = u;
                key[v] = adjacenyMatrix[u][v];
                q.insert(key[v],v);
            }
        }
        visited[u] = 1;
    }
    cout<<"MST Prim: ";
    int cost=0;
    for(int i=1;i<graphSize;i++){
        cout<<"["<<predecessor[i]<<"-"<<i<<"] ";
        cost += adjacenyMatrix[i][predecessor[i]];
    }

    cout<<" cost:"<<cost<<endl;
}

void Graph::print(){
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            cout<<"["<<adjacenyMatrix[i][j]<<"] ";
        }
        cout<<endl;
    }
}

#endif // GRAPH_H
