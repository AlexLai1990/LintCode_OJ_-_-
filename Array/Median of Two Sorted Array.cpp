double findMedianSortedArrays(vector<int> A, vector<int> B) {
    // write your code here
    int total_size = A.size() + B.size();
    // if the total size is odd
    if (total_size & 0x1) {
        return findkth(A, B, total_size / 2 + 1, 0, 0);
    }
    else {
        return (findkth(A, B, total_size / 2, 0, 0) + 
                findkth(A, B, total_size / 2 + 1, 0, 0) ) / 2;
    }
}

// find the kth min in sorted array A, B; k is the order.
// each time when one middle value less than the other one, skip all these till mid + 1
double findkth(vector<int> &A, vector<int> &B, int k, int index_a, int index_b) {
    if (A.size() - index_a > B.size() - index_b)
       return findkth(B, A, k, index_b, index_a);
    if (A.size() - index_a == 0)
        return B[k - 1];
    if (k == 1) {
        return min(A[index_a], B[index_b]);
    }
    int mid_a = min((int)A.size() - index_a, k/2);
    int mid_b = k - mid_a;
    if (A[index_a + mid_a - 1] < B[index_b + mid_b - 1]) {
        return findkth(A, B, k - mid_a, index_a + mid_a, index_b); 
    }
    else if (A[index_a + mid_a - 1] > B[index_b + mid_b - 1]) {
        return findkth(A, B, k - mid_b, index_a, index_b + mid_b);
    }
    else 
        return A[mid_a - 1];
}