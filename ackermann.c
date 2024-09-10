#include <stdio.h>

#define m 1
#define n 1

int Ackermann(int a,int b){
    printf("a = %d b = %d\n",a,b);
    if (a == 0 && b >= 0){
        return b + 1;
    }
    else if (b == 0 && a > 0){
        Ackermann(a - 1,1);
    }
    else if (a > 0 && b > 0){
        Ackermann(a - 1,Ackermann(a,b-1));
    }
    return 0;
}


int main(){
    Ackermann(1,1);
    return 0;
}