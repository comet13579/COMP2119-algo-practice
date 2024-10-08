#include <stdio.h>

// Function prototype
int reOrder2(int *A, int n);

int main() {
    int A1[] = {7,14,23,26,43,60,81,3};
    int A2[] = {43, 60, 71, 81, 3, 14, 23, 26};  // length 8, expected k = 4
    int A3[] = {5, 6, 7, 8, 1, 2, 3, 4};  // length 8, expected k = 4
    int A4[] = {9, 10, 11, 12, 13, 14, 15, 16, 1, 2, 3, 4, 5, 6, 7, 8};  // length 16, expected k = 8
    int A5[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 1, 2};  // length 16, expected k = 2
    int A6[] = {17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};  // length 32, expected k = 16
    int A7[] = {2, 3, 4, 1};  // length 4, expected k = 3


    printf("1. The output is k = %d\n", reOrder2(A1,sizeof(A1) / sizeof(A1[0])));
    printf("2. The output is k = %d\n", reOrder2(A2,sizeof(A2) / sizeof(A2[0])));
    printf("3. The output is k = %d\n", reOrder2(A3,sizeof(A3) / sizeof(A3[0])));
    printf("4. The output is k = %d\n", reOrder2(A4,sizeof(A4) / sizeof(A4[0])));
    printf("5. The output is k = %d\n", reOrder2(A5,sizeof(A5) / sizeof(A5[0])));
    printf("6. The output is k = %d\n", reOrder2(A6,sizeof(A6) / sizeof(A6[0])));
    printf("7. The output is k = %d\n", reOrder2(A7,sizeof(A7) / sizeof(A7[0])));

    return 0;
}
