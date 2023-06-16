0x17. C - Doubly linked lists

A doubly linked list is a data structure that consists of a sequence of elements, where each element contains a reference to the previous and next elements in the list. Unlike a singly linked list, which only has a reference to the next element, a doubly linked list allows traversal in both directions.

Each element in a doubly linked list, commonly referred to as a node, contains three main components: the data or value it holds, a reference to the previous node (usually called "prev" or "previous"), and a reference to the next node (usually called "next").

Here's an example visual representation of a doubly linked list:

```
Node 1       Node 2       Node 3       Node 4
+------+    +------+    +------+    +------+
| data |    | data |    | data |    | data |
+------+    +------+    +------+    +------+
| prev |<-->| prev |<-->| prev |<-->| prev |
+------+    +------+    +------+    +------+
| next |<-->| next |<-->| next |<-->| next |
+------+    +------+    +------+    +------+
```

To use a doubly linked list:

1. Initialization: Create an empty doubly linked list by defining a head node and setting its previous and next references to null.

2. Insertion: To insert a new element, create a new node, assign the appropriate data, set its previous reference to the desired previous node, and update the next reference of the previous node and the previous reference of the next node accordingly.

3. Deletion: To remove an element, update the next reference of the previous node and the previous reference of the next node to bypass the node you want to delete. Make sure to properly handle edge cases when deleting the first or last node.

4. Traversal: You can traverse a doubly linked list either forward or backward. To traverse forward, start from the head node and follow the next references until you reach the end of the list. To traverse backward, start from the tail node (if available) and follow the previous references until you reach the beginning of the list.

5. Searching and accessing: Similar to traversal, you can search for specific elements by comparing their values as you traverse the list. Additionally, you can access elements at specific positions by iterating through the list or using indices.

Example of Doubly linked lists can be implemented in the C programming language.
#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to display the doubly linked list
void display(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* current = head;
    printf("Doubly linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the doubly linked list
int main() {
    Node* head = NULL;

    // Inserting nodes
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // Displaying the doubly linked list
    display(head);

    // Clean up the memory
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

