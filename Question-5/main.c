#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node *prev, *current, *next;
    prev = NULL;
    current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {

    struct Node* originalLinkedList = createNode(1);
    originalLinkedList->next = createNode(2);
    originalLinkedList->next->next = createNode(3);
    originalLinkedList->next->next->next = createNode(4);
    originalLinkedList->next->next->next->next = createNode(5);

    printf("Original Linked List: ");
    printList(originalLinkedList);

    struct Node* reversedLinkedList = reverseList(originalLinkedList);

    printf("Reversed Linked List: ");
    printList(reversedLinkedList);

    while (originalLinkedList != NULL) {
        struct Node* temp1 = originalLinkedList;
        originalLinkedList = originalLinkedList->next;
        free(temp1);

        struct Node* temp2 = reversedLinkedList;
        reversedLinkedList = reversedLinkedList->next;
        free(temp2);
    }

    return 0;
}

