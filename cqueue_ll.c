#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list queue
struct Node {
    int data;
    struct Node *next;
};

// Global declaration of rear pointer
struct Node *rear = NULL;

// Initialize queue (no need for this function since rear is already globally initialized to NULL)
void initialize() {
    rear = NULL; // Explicitly setting rear to NULL for clarity
}

// Check if queue is empty
int isEmpty() {
    return (rear == NULL);
}

// Enqueue operation
void enqueue(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (isEmpty()) {
        newNode->next = newNode; // Point to itself in a circular manner
        rear = newNode;
    } else {
        newNode->next = rear->next; // New node points to the front
        rear->next = newNode;       // Rear's next points to the new node
        rear = newNode;             // Update rear to the new node
    }
    
    printf("Inserted %d\n", data);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    
    struct Node *frontNode = rear->next; // Front node is rear->next in a circular queue
    printf("Deleted %d\n", frontNode->data);
    
    if (rear == frontNode) { // If there's only one node in the queue
        rear = NULL;         // Queue becomes empty
    } else {
        rear->next = frontNode->next; // Rear's next points to the new front
    }
    
    free(frontNode); // Free the memory of the dequeued node
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    
    printf("Queue Elements: ");
    struct Node *temp = rear->next; // Start from the front (rear->next)
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next); // Loop until we return to the front
    
    printf("\n");
}

// Main function
int main() {
    initialize(); // Initialize the queue
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    dequeue();
    display();
    
    enqueue(40);
    enqueue(50);
    display();
    
    return 0;
}