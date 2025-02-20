#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL; // Global head pointer

// Function to insert at the beginning
void insert_at_beginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL) {//it means linked list have one or more nodes.
        head->prev = new_node;
    }
    head = new_node;
}

// Function to insert at the end
void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {//no node 
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Function to insert at a specific position
void insert_at_position(int data, int position) {
    if (position < 1) {
        printf("Position must be greater than 0\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    new_node->data = data;

    if (position == 1) {
        new_node->next = head;
        new_node->prev = NULL;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is greater than the number of nodes\n");
        return;
    }

    new_node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to delete from the beginning
void delete_at_beginning() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

// Function to delete from the end
void delete_at_end() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;//traverse to last node.
    }

    if (last->prev != NULL) {//more than one node.
        last->prev->next = NULL;
    } else {//one node
        head = NULL;
    }

    free(last);
}

// Function to delete from a specific position
void delete_at_position(int position) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    if (position < 1) {
        printf("Position must be greater than 0\n");
        return;
    }

    struct Node* temp = head;
    
    if (position == 1) {//one node
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }                   

    if (temp == NULL) {
        printf("Position is greater than the number of nodes\n");
        return;
    }
//agar temp== null hota to upar wala block chalta,
// but temp!=null hota to neeche wala block chalta.
    if (temp->next != NULL) {// It means temp is not the last node.
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {// It means temp is not the first node.
        temp->prev->next = temp->next;
    }
   free(temp);
}

// Function to print the list
void print_list() {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the operations
int main() {
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_position(15, 2);
    insert_at_position(25, 4);
    
    printf("List after insertions:\n");
    print_list();

    delete_at_beginning();
    delete_at_end();
    delete_at_position(2);

    printf("List after deletions:\n");
    print_list();

    return 0;
}
