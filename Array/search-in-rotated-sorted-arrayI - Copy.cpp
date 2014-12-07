bool search(vector<int> &A, int target) {
    // write your code here
    if (A.size() < 1)
        return false;
    int start = 0;
    int end = A.size() - 1;
    int mid;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] == target)
            return true;
        else if (A[start] < A[mid]) {
            if (A[start] <= target && target <= A[mid]) {
                end = mid;
            }
            else {
                start = mid;
            }
        }
        else if (A[start] > A[mid]){
            if (A[mid] <= target && target <= A[end])
                start = mid;
            else 
                end = mid;
        }
        else 
            start++;
    }
    if (A[start] == target)
        return true;
    else if (A[end] == target)
        return true;
    else 
        return false;
}