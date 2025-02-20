#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
 struct Node* head = NULL;
// Function to insert at the beginning
void insertAtBeginning( int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;        
}

// Function to insert at the end
void insertAtEnd( int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) { //when no node is there the head points to NULL.
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to insert at a specific position (1-based index)
void insertAtPosition( int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) { // Insert at beginning
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)//element ke ek pehle tak jayega temp.
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete from the beginning
void deleteAtBeginning() {
    if (head == NULL) return;//head=NULL means no node is there.

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Function to delete from the end
void deleteAtEnd() {
    if (head == NULL) return;

    struct Node* temp = head, *prev = NULL;
    if (temp->next == NULL) { // Only one node
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Function to delete from a specific position
void deleteAtPosition( int position) {
    if (head == NULL || position < 1) return;

    struct Node* temp = head;

    if (position == 1) { // Delete first node
        head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {//element tak jana hai temp ko,aur prev uske ek pehle.
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
   

    insertAtEnd( 10);
    insertAtEnd(20);
    insertAtEnd( 30);
    printf("List after insertions at end: ");
    display();

    insertAtBeginning( 5);

        printf("List after insertion at beginning: ");
    display();

    insertAtPosition( 15, 3);
    printf("List after insertion at position 3: ");
    display();

    deleteAtBeginning();
    printf("List after deleting from beginning: ");
    display();

    deleteAtEnd();
    printf("List after deleting from end: ");
    display();

    deleteAtPosition( 2);
    printf("List after deleting from position 2: ");
    display();

    return 0;
}
