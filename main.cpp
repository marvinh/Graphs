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
    Graph<char>* graph1 = new Graph<char>(1);
    
    //this adds 9 more verticies
    graph1->addVertcies(9);
    
    //This example is from class
    //But include some islands
    //or disconnects
    
    std::cout<<"graph1: \n";
    graph1->addEdge(0,1,'b');
    graph1->addEdge(0,2,'c');
    graph1->addEdge(1,3,'d');
    graph1->addEdge(2,5,'f');
    graph1->addEdge(5,5,'f');
    graph1->addEdge(3,4,'e');
    graph1->addEdge(4,5,'f');
    graph1->addEdge(5,6,'g');
    
    
    graph1->print();
    
    std::cout<<std::endl;
    
    graph1->dfs(0);
    
    std::cout<<std::endl<<std::endl;

    //Another graph lots of disconnects
    std::cout<<"graph2: \n";
    Graph<char>* graph2 = new Graph<char>(8);
    graph2->addEdge(0,3);
    graph2->addEdge(1,3);
    graph2->addEdge(4, 6);
    graph2->addEdge(6, 4);
    graph2->addEdge(7, 5);

    graph2->print();
    
    std::cout<<std::endl;
    
    graph2->dfs(0);
    
    std::cout<<std::endl;

    return 0;
}
