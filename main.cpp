//
//  main.cpp
//  Graph
//
//  Created by marvin h on 10/26/15.
//  Copyright © 2015 marvin h. All rights reserved.
//

#include <iostream>
#include "Graph.h"
int main(int argc, const char * argv[]) {
    
    
    //graph needs init size
    Graph<char> graph1(7);
    std::cout<<"connected graph: \n";
    
    graph1.addEdge(0,1);
    graph1.addEdge(0,3);
    graph1.addEdge(1,2);
    graph1.addEdge(3,2);
    graph1.addEdge(3,4);
    graph1.addEdge(2,5);
    graph1.addEdge(4,5);
    graph1.addEdge(5,6);
    graph1.addEdge(6,6);
    
    graph1.print();
    std::cout<<"\n\nrun dfs\n";
    graph1.dfs(0);
    std::cout<<"\n\n";
    
    
    Graph<char> graph2(10);
    std::cout<<"graph with disconnects: \n";
    
    graph2.addEdge(0,1);
    graph2.addEdge(0,3);
    graph2.addEdge(1,2);
    graph2.addEdge(3,2);
    graph2.addEdge(3,4);
    graph2.addEdge(2,5);
    graph2.addEdge(4,5);
    graph2.addEdge(5,6);
    graph2.addEdge(6,6);
    graph2.addEdge(8,9);
    
    graph2.print();
    std::cout<<"\n\nrun dfs\n";
    graph2.dfs(0);
    std::cout<<"\n\n";
    
    return 0;
}
