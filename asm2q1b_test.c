#include <stdio.h>

// Function prototype
int reOrder2(int *A, int n);

int main() {
    int A1[] = {7,14,23,26,43,60,81,3};
    int n = sizeof(A1) / sizeof(A1[0]);

    int result = reOrder2(A1, n);

    printf("The output is k = %d\n", result);

    return 0;
}
