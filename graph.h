#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <climits>
#include "heap.h"

// This class represents a graph using an adjacency matrix.
// It includes a function to run Prim's algorithm to find the Minimum Spanning Tree (MST).
class Graph {
public:
    // Constructor: creates a VxV adjacency matrix and initializes weights
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                if (i == j)
                    adjMatrix[i][j] = 0; // Distance to itself is 0
                else
                    adjMatrix[i][j] = INT_MAX; // INT_MAX means no direct edge
            }
        }
    }

    // Destructor: releases memory used by the adjacency matrix
    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Adds an undirected edge between u and v with the given weight
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    // Optional: Prints the adjacency matrix (helps with debugging)
    void printMatrix() {
        std::cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] == INT_MAX)
                    std::cout << "∞\t";
                else
                    std::cout << adjMatrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    // Main function: Implements Prim’s algorithm to find and print MST
    void primMST() {
        int parent[100];    // Keeps track of the MST structure
        int key[100];       // Stores minimum weight edge for each vertex
        bool inMST[100];    // Tracks whether a vertex is included in MST

        // Initialization
        for (int i = 0; i < numVertices; i++) {
            key[i] = INT_MAX;
            inMST[i] = false;
            parent[i] = -1;
        }

        key[0] = 0; // Start from the first vertex

        MinHeap heap(numVertices);
        for (int i = 0; i < numVertices; i++) {
            heap.insert(i, key[i]);
        }

        // Loop until all vertices are in MST
        while (!heap.isEmpty()) {
            int u = heap.extractMin(); // Pick vertex with smallest key
            inMST[u] = true;

            // Check all neighbors of u
            for (int v = 0; v < numVertices; v++) {
                int w = adjMatrix[u][v]; // weight between u and v
                if (w != 0 && w != INT_MAX && !inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    heap.decreaseKey(v, w); // Update key value in heap
                }
            }
        }

        // Print the MST
        int total = 0;
        std::cout << "\nEdges in MST:\n";
        for (int i = 1; i < numVertices; i++) {
            std::cout << parent[i] << " - " << i << "   weight: " << adjMatrix[i][parent[i]] << "\n";
            total += adjMatrix[i][parent[i]];
        }
        std::cout << "Total weight: " << total << "\n";
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif
