class Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) { 
        int neg_size = 0, pos_size = 0;
        for (auto item : A) {
            if (item > 0) 
                pos_size++;
            else 
                neg_size++;
        }
        partitionArray(A, pos_size >= neg_size);
        int left = 0, right = A.size() - 1 - abs(pos_size - neg_size);
        while (left < A.size() && left >= 0 && right < A.size() && right >= 0 && left < right) {
            swap(A[left], A[right]);
            left += 2;
            right -= 2;
        }
        return A;
    }
    
    // if pos == true, it means that positive number not less than negative number 
    void partitionArray(vector<int> &A, bool pos) {
        int index = A.size() - 1;
        for (int i = A.size() - 1; i >= 0; i--) {
            if (pos == true && A[i] > 0)
                swap(A[index--], A[i]);
            if (pos == false && A[i] < 0)
                swap(A[index--], A[i]);
        } 
        return;
    }
};
