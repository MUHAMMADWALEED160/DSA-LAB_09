// Task 3
#include <iostream>
using namespace std;

// Class representing a single node in the queue
class Node {
public:
    int value;          // Stores an integer value
    Node* nextNode;    // Pointer to the next node in the queue

    // Constructor to create a node with a specific value
    Node(int val) : value(val), nextNode(nullptr) {}
};

// Class implementing a queue using a linked list structure
class Queue {
private:
    Node* frontNode;  // Pointer to the front of the queue
    Node* rearNode;   // Pointer to the rear of the queue
    int currentSize;  // Current number of elements in the queue
    int maxCapacity;   // Maximum capacity of the queue (5 in this case)

public:
    // Constructor to initialize an empty queue with a specified maximum size
    Queue(int maxCapacity = 5) : frontNode(nullptr), rearNode(nullptr), currentSize(0), maxCapacity(maxCapacity) {}

    // Method to check if the queue is empty
    bool isEmpty() const {
        return frontNode == nullptr;
    }

    // Method to check if the queue has reached its maximum capacity
    bool isFull() const {
        return currentSize == maxCapacity;
    }

    // Method to add a new value to the end of the queue (enqueue)
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue overflow! Cannot add more elements.\n";
            return;
        }
        Node* newNode = new Node(val);
        if (isEmpty()) {
            frontNode = rearNode = newNode; // If the queue is empty, front and rear point to the new node
        } else {
            rearNode->nextNode = newNode; // Link the new node to the rear
            rearNode = newNode;           // Update the rear pointer
        }
        currentSize++; // Increase the size of the queue
        cout << "Enqueued: " << val << endl;
    }

    // Method to remove a value from the front of the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! No elements to remove.\n";
            return -1; // Return -1 to indicate the queue is empty
        }
        Node* tempNode = frontNode; // Temporary pointer to hold the front node
        int removedValue = frontNode->value; // Store the value to be removed
        frontNode = frontNode->nextNode; // Move the front pointer to the next node
        if (frontNode == nullptr) {
            rearNode = nullptr; // If the queue is now empty, set rear to nullptr
        }
        delete tempNode; // Free memory of the removed node
        currentSize--; // Decrease the size of the queue
        return removedValue;
    }

    // Method to display the contents of the queue
    void display() const {
        if (isEmpty()) {
            cout << "The queue is empty.\n";
            return;
        }
        Node* currentNode = frontNode; // Start from the front
        cout << "Current queue elements: ";
        while (currentNode != nullptr) {
            cout << currentNode->value << " "; // Print each element
            currentNode = currentNode->nextNode; // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    Queue queue1(5); // Create the first queue of size 5
    Queue queue2(5); // Create the second queue of size 5

    int userChoice, valueInput;
    do {
        cout << "\nMenu Options:\n1. Add value to Queue 1\n2. Remove from Queue 1 and add to Queue 2\n";
        cout << "3. Remove from Queue 2\n4. Show Queue 1\n5. Show Queue 2\n6. Exit\n";
        cout << "Please enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                // Add a value to Queue 1
                cout << "Enter a value to add to Queue 1: ";
                cin >> valueInput;
                queue1.enqueue(valueInput);
                break;

            case 2: {
                // Remove from Queue 1 and add to Queue 2
                int dequeuedValue = queue1.dequeue();
                if (dequeuedValue != -1) {
                    queue2.enqueue(dequeuedValue); // Add the removed value to Queue 2
                }
                break;
            }

            case 3:
                // Remove a value from Queue 2
                queue2.dequeue();
                break;

            case 4:
                // Show contents of Queue 1
                queue1.display();
                break;

            case 5:
                // Show contents of Queue 2
                queue2.display();
                break;

            case 6:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid option, please try again!" << endl;
        }
    } while (userChoice != 6);

    return 0;
}
