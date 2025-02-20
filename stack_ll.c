#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Global declaration of stack top pointer
struct Node *top = NULL;

// Initialize stack (not strictly necessary since globals are initialized to NULL)
void initialize() {
    top = NULL;
}

// Check if stack is empty
int isEmpty() {
    return (top == NULL);
}

// Push operation
void push(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", data);
}

// Pop operation
void pop() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Top Element: %d\n", top->data);
}

// Display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack Elements: ");
    struct Node *temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
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