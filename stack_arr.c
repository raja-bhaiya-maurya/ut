#include <stdio.h>
#define MAX 5  // Stack size

// Global declarations of stack elements
int arr[MAX];   // Array to hold stack elements
int top = -1;   // Top index of the stack

// Initialize stack
void initialize() {
    top = -1;
}

// Check if stack is empty
int isEmpty() {
    return (top == -1);
}

// Check if stack is full
int isFull() {
    return (top == MAX - 1);
}

// Push operation
void push(int data) {
    if (isFull()) {
        printf("Stack is Full!\n");
        return;
    }
    arr[++top] = data;
    printf("Pushed %d\n", data);
}

// Pop operation
void pop() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Popped %d\n", arr[top--]);
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Top Element: %d\n", arr[top]);
}

// Display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack Elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    initialize();
    
    push(10);
    push(20);
    push(30);
    display();
    
    pop();
    peek();
    display();
    
    push(40);
    push(50);
    display();
    
    return 0;
}