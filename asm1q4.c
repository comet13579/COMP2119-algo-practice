#include  <stdio.h>

int _exp2(int n){
    if (n == 1){
        return 2;
    }
    if (n % 2 == 0){
        int temp = _exp2(n/2);
        return temp * temp;
    }
    else{
        int temp = _exp2(n/2);
        return 2 * temp * temp;
    }
}

int main(){
    int n = 30;
    printf("%d\n",_exp2(n));
}