int reOrder2(int *A, int n){
    int prev,next;
    int k = n / 2;
    while (1){
        next = A[k];
        prev = A[k - 1];
        if (prev > next){
            return n - k;
        }
        if (prev < A[0]){
            k = k / 2;
        }
        else{
            k = k + (n - k) / 2;
        }
    }
}