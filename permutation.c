// print out all possible arrangements of a set of characters
#include <stdio.h>

char inputarray[] = {'a', 'b','c','d'};
int arraysize = sizeof(inputarray) / sizeof(char);

void twoValueSwap(char* ptr1, char* ptr2){
    char temp;
    temp = * ptr1;
    * ptr1 = * ptr2;
    * ptr2 = temp;
}

void printarray(char* array,int size){
    for (int i = 0;i < size; i++){
        printf("%c ",array[i]);
    }
    printf("\n");
}

void permutation(char* array,int size){
    if (size == 1){
        printarray(array,arraysize);
    }
    else{
        for (int i = 0; i < size; i++){
            twoValueSwap(&array[i],&array[size-1]);
            permutation(array,size-1);
            twoValueSwap(&array[i],&array[size-1]);
        }
    }
}

int main(){
    printarray(inputarray,arraysize);
    printf("Permutation demonstration: \n");
    permutation(inputarray,arraysize);
}