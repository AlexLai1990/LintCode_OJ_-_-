int findPeak(vector<int> A) {
    // write your code here
    int ret_index = -1;
    int start = 0, end = A.size() - 1;
    int mid;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (mid - 1 >= 0 && mid + 1 <= A.size() -1 && 
            A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            return mid;
        else if (mid + 1 <= A.size() - 1 && A[mid] < A[mid + 1])
            start = mid;
        else if (mid - 1 >= 0 && A[mid] < A[mid - 1])
            end = mid;
    }
    if (start == 0 || end == A.size() - 1)
        return ret_index;   
    if (A[start - 1] < A[start] && A[start] > A[end])
        return start;
    if (A[start] < A[end] && A[end] > A[end + 1])
        return end;
    return ret_index;
} 