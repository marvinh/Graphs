#include "Graph.h"
int main()
{
    //Undirected graph
    Graph g(9,false);

    g.addEdge( 0, 1, 4);
    g.addEdge( 0, 7, 8);
    g.addEdge( 1, 2, 8);
    g.addEdge( 1, 7, 11);
    g.addEdge( 2, 3, 7);
    g.addEdge( 2, 8, 2);
    g.addEdge( 2, 5, 4);
    g.addEdge( 3, 4, 9);
    g.addEdge( 3, 5, 14);
    g.addEdge( 4, 5, 10);
    g.addEdge( 5, 6, 2);
    g.addEdge( 6, 7, 1);
    g.addEdge( 6, 8, 6);
    g.addEdge( 7, 8, 7);

    g.dfs(0);
    g.bfs(0);

    g.dijkstraRun(0,1);
    g.dijkstraRun(0,2);
    g.dijkstraRun(0,3);
    g.dijkstraRun(0,4);
    g.dijkstraRun(0,5);
    g.dijkstraRun(0,6);
    g.dijkstraRun(0,7);
    g.dijkstraRun(0,8);

    g.mstPrim(0);

    g.print();

    return 0;
}
