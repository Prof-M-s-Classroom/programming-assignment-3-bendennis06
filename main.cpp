#include <iostream>
#include "graph.h"

int main() {

    /*Graph g(6);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 7);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 8);
    g.addEdge(4, 5, 9);*/

    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.printMatrix();
    g.primMST();


    return 0;
}