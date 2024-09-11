#include <stdio.h>

#define m 3
#define n 4

int Ackermann(int a,int b){
    if (a == 0){
        return b + 1;
    }
    else if (b == 0){
        return Ackermann(a - 1,1);
    }
    else{
        return Ackermann(a - 1,Ackermann(a,b-1));
    }
}


int main(){
    printf("ackermann: %d \n",Ackermann(m,n));
    return 0;
}