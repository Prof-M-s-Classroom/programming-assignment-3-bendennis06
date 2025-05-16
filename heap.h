#ifndef HEAP_H
#define HEAP_H

#include <climits>

// A simple custom MinHeap class that stores vertex indices and their key values
class MinHeap {
public:
    // Constructor: initializes arrays
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];

        // Fill with default values
        for (int i = 0; i < capacity; i++) {
            heapArray[i] = i;
            keyArray[i] = INT_MAX;
            position[i] = i;
            size++;
        }
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    // Sets the key value for a vertex
    void insert(int vertex, int key) {
        keyArray[vertex] = key;
    }

    // Returns the index of the vertex with the smallest key and removes it
    int extractMin() {
        int minKey = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < capacity; i++) {
            if (position[i] != -1 && keyArray[i] < minKey) {
                minKey = keyArray[i];
                minIndex = i;
            }
        }
        position[minIndex] = -1; // Mark as removed
        return minIndex;
    }

    // Updates the key value of a vertex
    void decreaseKey(int vertex, int newKey) {
        keyArray[vertex] = newKey;
    }

    // Checks if a vertex is still in the heap
    bool isInMinHeap(int vertex) {
        return position[vertex] != -1;
    }

    // Returns true if all elements are removed
    bool isEmpty() {
        for (int i = 0; i < capacity; i++) {
            if (position[i] != -1)
                return false;
        }
        return true;
    }

private:
    int* heapArray;
    int* keyArray;
    int* position;
    int capacity;
    int size;
};

#endif
