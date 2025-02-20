#include <stdio.h>
#define MAX 5  // Maximum size of circular queue

// Global declarations of circular queue elements
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
    return ((rear + 1) % MAX == front);
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
        rear = (rear + 1) % MAX;
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
    } else { //modulo handles all cases (both single-element and multi-element queues) in a uniform way.
        front = (front + 1) % MAX;//modulus ke bina bhi kaam ho jayega,magr modulus har case ke liye sahi hai.
    }                               //modulo will also help you if you forgot to put the (f==r) case.
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue Elements: ");
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    initialize();
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    
    dequeue();
    display();
    
    enqueue(60);
    display();
    
    return 0;
}