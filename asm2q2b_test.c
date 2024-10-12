#include <stdio.h>
#include <stdlib.h>
#include "asm2q2b.c"

struct listNode* createNode(int data) {
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct listNode* head, struct listNode* cycleNode) {
    struct listNode* current = head;
    while (current != NULL && current != cycleNode) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    if (cycleNode != NULL) {
        printf("%d (cycle starts here)\n", cycleNode->data);
    } else {
        printf("NULL\n");
    }
}

int main() {
    // Create a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 3
    struct listNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = head->next->next;  // Create cycle

    printf("Original list with cycle: ");
    printList(head, head->next->next);

    struct listNode* cycleStart = getBeginNode(head);

    if (cycleStart != NULL) {
        printf("Cycle detected. It starts at node with value: %d\n", cycleStart->data);
    } else {
        printf("No cycle detected.\n");
    }

    return 0;
}
