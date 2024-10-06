#include <stdlib.h>
//not finished yet

struct listNode {
    int data;               // Data stored in the node
    struct listNode* next;  // Pointer to the next node
};
typedef struct listNode ListNode;

double findAverageCycleLength(ListNode * arrPtr, int n){
    int cycleSum = 0;
    for (int i = 0;i < n;i++){
        //Floyd's tortoise and hare algorithm
        ListNode * tortoise = arrPtr + i;
        ListNode * hare = arrPtr + i;
        int cycleLength = 0;
        int countcyclebool = 0;
        while (tortoise != NULL && hare != NULL && hare->next != NULL){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (countcyclebool == 1){
                cycleLength++;
            }
            if (countcyclebool == 1 && tortoise == hare){
                cycleSum += cycleLength;
                break;
            }
            if (tortoise == hare && countcyclebool == 0){
                countcyclebool = 1;
            }
        }
    }
    return (double)cycleSum/n;
}