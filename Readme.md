[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Your Name Here
Benjamin Dennis
## Description
Briefly describe what your program does and how the code is structured.

Basically, the program picks the cheapest edge that connects a new vertex each time, 
building up a tree that covers all vertices with the smallest total weight.


## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | 0(1)            |
| Extract Min          | 0(V)            |
| Decrease Key         | 0(1)            |
| Prim’s MST Overall   | 0(V^2)          |

_Explain why your MST implementation has the above runtime._

Since my heap uses a simple linear search to find the min, it’s not the most efficient. 
But it works well for small graphs and was easier to understand and build from scratch. 
If we used a binary heap, it would be O(E log V).


## Test Case Description

Input:  Graph g(6);
g.addEdge(0, 1, 3);
g.addEdge(0, 2, 1);
g.addEdge(1, 2, 7);
g.addEdge(1, 3, 5);
g.addEdge(2, 3, 4);
g.addEdge(2, 4, 6);
g.addEdge(3, 4, 2);
g.addEdge(3, 5, 8);
g.addEdge(4, 5, 9);


