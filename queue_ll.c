#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Global declarations of queue elements
struct Node *front = NULL; // Front pointer of the queue
struct Node *rear = NULL;  // Rear pointer of the queue

// Initialize queue (not strictly necessary since globals are initialized to NULL)
void initialize() {
    front = NULL;
    rear = NULL;
}

// Check if queue is empty
int isEmpty() {
    return (front == NULL);
}

// Enqueue operation
void enqueue(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d\n", data);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted %d\n", temp->data);

    front = front->next;

    if (front == NULL) { // If the queue becomes empty after dequeue
        rear = NULL;
    }

    free(temp); // Free the memory of the dequeued node
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front Element: %d\n", front->data);
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue Elements: ");
    struct Node *temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    initialize();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    peek();
    display();

    enqueue(40);
    enqueue(50);
    display();

    return 0;
}