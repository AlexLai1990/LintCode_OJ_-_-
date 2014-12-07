class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    enum DIRECTION {LEFT, RIGHT};
    
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> m_range(2, -1);
        if (A.size() < 1)
            return m_range;
        m_range[0] = findFirst(A, LEFT, target);
        m_range[1] = findFirst(A, RIGHT, target);
        return m_range;
    }
    
    // find first of one direction
    int findFirst(vector<int> &A, DIRECTION direction, int target) { 
        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (direction == LEFT) {
                if (A[mid] >= target) 
                    end = mid;
                else 
                    start = mid;
            }
            else if (direction == RIGHT) {
                if (A[mid] <= target)
                    start = mid;
                else
                    end = mid;
            }
        }
        if (direction == LEFT) {
            if (A[start] == target)
                return start;
            if (A[end] == target)
                return end;
            return -1;
        }
        if (direction == RIGHT) {
            if (A[end] == target)
                return end; 
            if (A[start] == target)
                return start;
            return -1;
        }
    }
};
