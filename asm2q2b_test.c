#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int data;               // Data stored in the node
    struct listNode* next;  // Pointer to the next node
};
typedef struct listNode ListNode;

ListNode * getBeginNode(ListNode * arrPtr);

// Function to create a new node
ListNode* createNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list (up to 20 nodes to avoid infinite loop)
void printList(ListNode* head) {
    ListNode* current = head;
    int count = 0;
    while (current != NULL && count < 20) {
        printf("%d -> ", current->data);
        current = current->next;
        count++;
    }
    printf("...\n");
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3 (cycle)
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = head->next->next; // Create cycle

    printf("Original list (limited to 20 nodes): ");
    printList(head);

    ListNode* cycleStart = getBeginNode(head);

    if (cycleStart != NULL) {
        printf("Cycle detected! The cycle begins at node with value: %d\n", cycleStart->data);
    } else {
        printf("No cycle detected.\n");
    }

    // Test case with no cycle
    ListNode* noCycleList = createNode(1);
    noCycleList->next = createNode(2);
    noCycleList->next->next = createNode(3);

    printf("List without cycle: ");
    printList(noCycleList);

    cycleStart = getBeginNode(noCycleList);

    if (cycleStart != NULL) {
        printf("Cycle detected! The cycle begins at node with value: %d\n", cycleStart->data);
    } else {
        printf("No cycle detected.\n");
    }

    return 0;
}
