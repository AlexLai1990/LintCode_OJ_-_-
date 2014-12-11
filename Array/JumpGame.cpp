class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here'
        if (A.size() <= 1)
            return true;
        int start = 0, end = 0;
        while (start <= end) {
            int temp_reach = start + A[start];
            if (temp_reach >= A.size() - 1)
                return true;
            if (temp_reach > end)
                end = temp_reach;
            start++;
        }
        return false;
    }
};

