#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the deque

// Global deque elements
int L_deque[MAX];
int front = -1;
int rear = -1;
//note:store chahe jahan bhi karaye array me ,but jab wo 
//print karayega tab front se rear tak backtrack karega.
// Initialize the deque
void initDeque() {
    front = -1;
    rear = -1;
}

// Check if the deque is full (overflow condition)
int isFull() {
    return (rear == MAX - 1);
}

// Check if the deque is empty (underflow condition)
int isEmpty() {
    return (front == -1);
}

// Insert at the front
void insertFront(int value) {
    if (front==0) {  // Overflow condition(different in linear and circular deque)
        printf("Overflow: Cannot insert at front\n");
        return;
    }
    
    if (isEmpty()) {  // First element insertion
        front = 0;
        rear = 0;
      
    } else {
        front--;
        
    }
    L_deque[front] = value;
     printf("insert_front: %d\n",L_deque[front]);
}

// Insert at the rear
void insertRear(int value) {
    if (isFull()) {  // Overflow condition
        printf("Overflow: Cannot insert at rear\n");
        return;
    }
 
    if (isEmpty()) {  // First element insertion
        front = 0;
        rear = 0;
        
    }  else {
        rear++;
       } 
       L_deque[rear] = value;printf("insert_rear: %d\n",L_deque[rear]);
}

// Delete from the front
void deleteFront() {
    if (isEmpty()) {  // Underflow condition
        printf("Underflow: Cannot delete from front\n");
        return;
    }
 printf("delete_front: %d\n",L_deque[front]);
    if (front == rear) {  // Only one element left
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

// Delete from the rear
void deleteRear() {
    if (isEmpty()) {  // Underflow condition
        printf("Underflow: Cannot delete from rear\n");
        return;
    }
 printf("delete_rear: %d\n",L_deque[rear]);
    if (front == rear) {  // Only one element left
        front = -1;
        rear = -1;
    } else {
        rear--;
    }
}

// Display the deque elements
void display() {
 if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", L_deque[i]);
    }
    printf("\n");
        
 }


int main() {
    initDeque();

    insertFront(10); display();insertFront(20);display();insertFront(33);display();
    // insertRear(20);
    insertFront(30);
    display();
    insertRear(30);display();insertRear(30);

    deleteFront();
    display();

    deleteRear();
    display();

    return 0;
}
