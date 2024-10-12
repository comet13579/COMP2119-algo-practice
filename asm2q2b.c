//C language
#include <stdlib.h>

struct listNode {
    int data;               // Data stored in the node
    struct listNode* next;  // Pointer to the next node
};
typedef struct listNode ListNode;

ListNode ** getLinkedListCyclePointers(ListNode * arrPtr, int *length){
    //Floyd's tortoise and hare algorithm
    ListNode * tortoise = arrPtr;
    ListNode * hare = arrPtr;
    ListNode ** returnArray = NULL; //array of pointers to the nodes in the cycle
    int cycleLength = 0;
    int cyclecount = 0; //count the number of rounds went through a loop
    while (tortoise != NULL && hare != NULL && hare->next != NULL){
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (cyclecount == 1){
            cycleLength++;
        }

        if (cyclecount == 2){
            returnArray[*length] = tortoise;
            (*length)++;
            if (tortoise == hare){
                return returnArray;
            }
        }

        if (cyclecount  == 1 && tortoise == hare){
            returnArray = (ListNode **) malloc(sizeof(ListNode *) * cycleLength);
            returnArray[*length] = tortoise;
            (*length)++;
            cyclecount = 2;
        }

        if (tortoise == hare && cyclecount == 0){
            cyclecount = 1;
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
//q2b