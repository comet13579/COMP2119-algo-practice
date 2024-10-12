//C language
#include <stdlib.h>

struct linkedlist {
    int data;
    struct linkedlist * next;
};

struct linkedlist * merge(struct linkedlist * head1, struct linkedlist * head2){
    struct linkedlist * start;
    struct linkedlist * add;
    struct linkedlist * tempptr;
    if (head1 -> data < head2 -> data){
        start = head1;
        add = head2;
    }
    else{
        start = head2;
        add = head1;
    }
    struct linkedlist * ongoing = start;
    while (ongoing -> next != NULL && add != NULL){
        if (add -> data < ongoing -> next -> data){
            tempptr = ongoing -> next;
            ongoing -> next = add;
            add = add -> next;
            ongoing -> next -> next = tempptr;
        }
        ongoing = ongoing -> next;
    }
    return start;
}
//q2a