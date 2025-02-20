#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the deque

// Global deque elements
int C_deque[MAX];
int front = -1;
int rear = -1;

// Initialize the deque
void initDeque() {
    front = -1;
    rear = -1;
}

// Check if the deque is full (overflow condition)
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Check if the deque is empty (underflow condition)
int isEmpty() {
    return (front == -1);
}

// Insert at the front
void insertFront(int value) {
    if (isFull()) {  // Overflow condition
        printf("Overflow: Cannot insert at front\n");
        return;
    }
printf("insert_front: %d\n",value);
    if (isEmpty()) {  // First element insertion
        front = 0;
        rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    
    C_deque[front] = value;
}

// Insert at the rear
void insertRear(int value) {
    if (isFull()) {  // Overflow condition
        printf("Overflow: Cannot insert at rear\n");
        return;
    }
printf("insert_rear: %d\n",value);
    if (isEmpty()) {  // First element insertion
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    
    C_deque[rear] = value;
}

// Delete from the front
void deleteFront() {
    if (isEmpty()) {  // Underflow condition
        printf("Underflow: Cannot delete from front\n");
        return;
    }
printf("delete_front: %d\n",C_deque[front]);
    if (front == rear) {  // Only one element left
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Delete from the rear
void deleteRear() {
    if (isEmpty()) {  // Underflow condition
        printf("Underflow: Cannot delete from rear\n");
        return;
    }
 printf("delete_rear: %d\n",C_deque[rear]);
    if (front == rear) {  // Only one element left
        front = -1;
        rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// Display the deque elements
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
 printf("display element: ");
    int i = front;
    while (1) {
        printf("%d ", C_deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
     initDeque();

    insertRear(10); display();insertRear(20);display();insertRear(33);display();
    // insertRear(20);
    insertRear(30);
    display();
    insertRear(30);display();insertRear(30);

    deleteFront();
    display();

    deleteRear();
    display();


    return 0;
}
