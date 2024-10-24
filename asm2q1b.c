int reOrder2(int *A, int n){
    // binary search for the lowest point
    // A[n - 1] < A[0] always true
    int prev,next;
    int k = n / 2;
    while (1){
        next = A[k];
        prev = A[k - 1];

        if (prev > next){
            return n - k;
        }

        //fixing the case when k == 0
        if (k == n - 1){
            return 0;
        }
        
        if (prev < A[0]){
            k = k / 2;
        }
        else{
            k = k + (n - k) / 2;
        }
    }
}