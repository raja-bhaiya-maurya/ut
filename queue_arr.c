#include <stdio.h>
#define MAX 5  // Queue size

// Global declarations of queue elements
int arr[MAX];   // Array to hold queue elements
int front = -1; // Front index of the queue
int rear = -1;  // Rear index of the queue

// Initialize queue
void initialize() {
    front = -1;
    rear = -1;
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Enqueue operation
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is Full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    arr[rear] = data;
    printf("Inserted %d\n", data);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Deleted %d\n", arr[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front Element: %d\n", arr[front]);
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
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