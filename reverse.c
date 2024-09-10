#include <stdio.h>

int array[] = {5,3,1,4,8,8,3,9,9,3,1,7,3,7,2,5,1,6};

void reverse(int *firstelement, int *lastelement){
    if (firstelement >= lastelement){
        return;
    }
    int temp = *firstelement;
    *firstelement = *lastelement;
    *lastelement = temp;
    reverse(firstelement+1, lastelement-1);
}

int main(){
    int size = sizeof(array) / sizeof(array[0]);
    reverse((int *)&array,(int *)&array + size - 1);
        for (int *i = array; i < array + size; i++) {
            printf("%d ", *i);
        }
        printf("\n");}