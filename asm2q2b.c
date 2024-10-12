#include <stdlib.h>
#include <stdbool.h>

struct listNode {
    int data;               // Data stored in the node
    struct listNode* next;  // Pointer to the next node
};
typedef struct listNode ListNode;

ListNode ** getLinkedListCyclePointers(ListNode * arrPtr, int *length){
    //Floyd's tortoise and hare algorithm
    //copied from COMP2113 Assignment 4
    ListNode * tortoise = arrPtr;
    ListNode * hare = arrPtr;
    ListNode ** returnArray = NULL; //array of pointers to the nodes in the cycle
    int cycleLength = 0;
    int countcyclecount = 0;
    while (tortoise != NULL && hare != NULL && hare->next != NULL){
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (countcyclecount == 1){
            cycleLength++;
        }

        if (countcyclecount == 2){
            returnArray[*length] = tortoise;
            (*length)++;
            if (tortoise == hare){
                return returnArray;
            }
        }

        if (countcyclecount  == 1 && tortoise == hare){
            returnArray = (ListNode **) malloc(sizeof(ListNode *) * cycleLength);
            returnArray[*length] = tortoise;
            (*length)++;
            countcyclecount = 2;
        }

        if (tortoise == hare && countcyclecount == 0){
            countcyclecount = 1;
        }
    }
    return NULL; // return NULL if there is no cycle
}

int checkInList(ListNode *arrPtr, ListNode **arrPtrLst, int *length) {
    int i;
    for (i = 0; i < *length; i++) {
        if (arrPtr == arrPtrLst[i]) {
            return 1;
        }
    }
    return 0;
}

ListNode * getBeginNode(ListNode * arrPtr){
    int length = 0;
    ListNode ** cyclingPointer = getLinkedListCyclePointers(arrPtr, &length);
    ListNode * ongoingPointer = arrPtr;
    if (cyclingPointer == NULL){
        return NULL;
    }
    
    while (1){
        if (checkInList(ongoingPointer, cyclingPointer, &length) == 1){
            return ongoingPointer;
        }
        ongoingPointer = ongoingPointer->next;
    }
}