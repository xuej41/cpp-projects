#include "cmdQueue.h"

#include <iostream>
using namespace std;

// Available Data Members from cmdQueue.h

// You must implement the array-based circular queue as discussed in class

// You must NOT use any existing data structures such as Lists to design the queue.


cmdQueue::cmdQueue()
{
    // Constructor
    capacity = DEFAULT_CAPACITY;
    queue = new char[capacity];
    size = 0;
    front = 0;
    end = -1;
}

cmdQueue::cmdQueue(int cap)
{
    // Additional Constructor
    capacity = cap;
    queue = new char[capacity];
    size = 0;
    front = 0;
    end = -1;
}

cmdQueue::~cmdQueue()
{
    // Destructor 
    delete[] queue;
}

void cmdQueue::enqueue(char thisCmd)
{
    // Enqueue into Circular Queue
    if (size == capacity) {
        cout << "Queue is full!" << endl;
        return;
    }
    end = (end + 1) % capacity;
    queue[end] = thisCmd;
    size++;
}

char cmdQueue::dequeue()
{
    // Dequeue from Circular Queue
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return '\0';
    }
    char removed = queue[front];
    front = (front + 1) % capacity;
    size--;
    return removed;
}

int cmdQueue::getSize() const
{
    // Return the size of the Queue
    return size;
}

void cmdQueue::clearQueue()
{
    // Remove all elements from the Queue
    size = 0;
    front = 0;
    end = -1;
}

void cmdQueue::printMe() const
{
    // NOT GRADED
    //  Print the contents of the Queue
    
    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue contents: ";
    for (int i = 0; i < size; i++) {
        cout << queue[(front + i) % capacity] << " ";
    }
    cout << endl;
}