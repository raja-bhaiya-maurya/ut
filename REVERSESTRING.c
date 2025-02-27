#include <stdio.h>
#include <string.h>

#define MAX 100  

// Global stack variables
char stack[MAX];
int top = -1;

// Stack operations
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    return (top >= 0) ? stack[top--] : '\0';
}

// Function to reverse a string using stack
void reverseString(char str[]) {
    int len = strlen(str);

    // Push all characters onto stack
    for (int i = 0; i < len; i++)
        push(str[i]);

    // Pop characters to get reversed string
    for (int i = 0; i < len; i++)
        str[i] = pop();
}

int main() {
    char str[] = "Hello";
    printf("Original String: %s\n", str);
    
    reverseString(str);
    
    printf("Reversed String: %s\n", str);
    return 0;
}
