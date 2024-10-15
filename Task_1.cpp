//Task 2
#include <iostream>
#include <string>

using namespace std;

// Class representing a person
class Person {
private:
    int id;              // Changed variable name for clarity
    string name;        // Changed variable name for clarity
    int age;            // Changed variable name for clarity

public:
    // Default constructor to initialize a person
    Person() : id(0), name(""), age(0) {}

    // Method to input person details from user
    void enterDetails() {
        cout << "Please enter Person ID: ";
        cin >> id;
        cout << "Please enter Person Name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, name);
        cout << "Please enter Person Age: ";
        cin >> age;
    }

    // Method to display the person's details
    void showDetails() const {
        cout << "Person ID: " << id << endl;
        cout << "Person Name: " << name << endl;
        cout << "Person Age: " << age << endl;
    }
};

// Node class to represent each element in the linked list
class Node {
public:
    Person personData; // Stores a Person object
    Node* nextNode;    // Pointer to the next node

    // Constructor to initialize a new node
    Node(const Person& p) : personData(p), nextNode(nullptr) {}
};

// Class implementing a queue using a linked list
class Queue {
private:
    Node* frontNode; // Pointer to the front of the queue
    Node* rearNode;  // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    // Destructor to free all allocated nodes in the queue
    ~Queue() {
        while (!isEmpty()) {
            removeFromQueue(); // Remove all nodes when the queue is destroyed
        }
    }

    // Method to check if the queue is empty
    bool isEmpty() const {
        return frontNode == nullptr;
    }

    // Method to add a person to the end of the queue
    void addToQueue(const Person& p) {
        Node* newNode = new Node(p);
        if (isEmpty()) {
            frontNode = rearNode = newNode; // If the queue is empty, set both front and rear to the new node
        } else {
            rearNode->nextNode = newNode; // Link the new node to the end of the queue
            rearNode = newNode;           // Update the rear pointer to the new node
        }
        cout << "Person has been added to the queue!" << endl;
    }

    // Method to remove a person from the front of the queue
    void removeFromQueue() {
        if (isEmpty()) {
            cout << "The queue is empty, nothing to remove!" << endl;
        } else {
            Node* tempNode = frontNode;     // Temporary pointer to hold the node being removed
            frontNode = frontNode->nextNode; // Move the front pointer to the next node
            cout << "Removing person from the queue: " << endl;
            tempNode->personData.showDetails(); // Display the person being removed
            delete tempNode;                    // Free the memory of the removed node

            if (frontNode == nullptr) {
                rearNode = nullptr;             // If the queue is empty, reset the rear pointer
            }
        }
    }
};

int main() {
    Queue personQueue; // Create a queue for person objects
    int choice;

    do {
        cout << "\nMenu Options:\n1. Add Person to Queue\n2. Remove Person from Queue\n3. Exit\nSelect an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add a person to the queue
                Person newPerson;
                newPerson.enterDetails(); // Get person details
                personQueue.addToQueue(newPerson);
                break;
            }
            case 2:
                // Remove a person from the queue
                personQueue.removeFromQueue();
                break;
            case 3:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid option, please try again!" << endl;
        }
    } while (choice != 3);

    return 0;
}
