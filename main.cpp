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
    Graph<char> graph1(1);
    
    //this adds 9 more verticies
    graph1.addVertcies(9);
    
    //This example is similar to 
	//the first done in class
    //but includes some islands
    //or disconnects

    std::cout<<"graph1: \n";
    graph1.addEdge(0,1,'b');
    graph1.addEdge(0,2,'c');
    graph1.addEdge(1,3,'d');
    graph1.addEdge(2,5,'f');
    graph1.addEdge(5,5,'f');
    graph1.addEdge(3,4,'e');
    graph1.addEdge(4,5,'f');
    graph1.addEdge(5,6,'g');
    graph1.print();
    graph1.addVertcies(1);
    std::cout<<"\n";
    graph1.addEdge(0,9,'z');
    graph1.print();
	graph1.dfs(0);
	std::cout<<"\n";
	graph1.print();


    return 0;
}
