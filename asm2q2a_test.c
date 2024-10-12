#include <stdio.h>
#include <stdlib.h>

struct linkedlist {
    int data;
    struct linkedlist * next;
};

// Function prototype for merge
struct linkedlist * merge(struct linkedlist * head1, struct linkedlist * head2);

// Helper function to create a new node
struct linkedlist* newNode(int data) {
    struct linkedlist* node = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    node->data = data;
    node->next = NULL;
    return node;
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
    // Create first sorted linked list: 1 -> 3 -> 5 -> 7
    struct linkedlist* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);
    head1->next->next->next = newNode(7);

    // Create second sorted linked list: 2 -> 4 -> 6 -> 8
    struct linkedlist* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);
    head2->next->next->next = newNode(8);

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
