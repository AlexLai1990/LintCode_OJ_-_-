class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int total = m + n; 
        int index_a = m - 1;
        int index_b = n - 1;
        int end = total - 1;
        while (index_a >= 0 && index_b >= 0) {
            if (A[index_a] > B[index_b])
                A[end--] = A[index_a--];
            else 
                A[end--] = B[index_b--]; 
        } 
        while (index_a >= 0) {
            A[end--] = A[index_a--];
        }
        while (index_b >= 0) {
            A[end--] = B[index_b--];
        }
        return;
    }
};
