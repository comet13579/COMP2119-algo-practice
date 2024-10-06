#include <stdio.h>
#include <stdlib.h>

// Include the struct definition and merge function from asm2q2a.c
#include "asm2q2a.c"

// Helper function to create a new node
struct linkedlist* createNode(int data) {
    struct linkedlist* newNode = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct linkedlist* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create the first sorted linked list: 1 -> 3 -> 5 -> 7
    struct linkedlist* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);
    head1->next->next->next = createNode(7);

    // Create the second sorted linked list: 2 -> 4 -> 6 -> 8
    struct linkedlist* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(8);

    printf("First list: ");
    printList(head1);
    printf("Second list: ");
    printList(head2);

    // Merge the two lists
    struct linkedlist* mergedList = merge(head1, head2);

    printf("Merged list: ");
    printList(mergedList);

    return 0;
}
