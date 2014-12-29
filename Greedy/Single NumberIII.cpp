class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        vector<int> m_res;
        if (A.size() < 2)
            return m_res;
        int two_left = 0;
        for (int i = 0; i < A.size(); i++) {
            two_left ^= A[i];
        }
        int mask = 0;
        for (int i = 0; i < 32; i++) {
            if ((two_left & (1 << i)) != 0) {
                mask = 1 << i;
                break;
            }
        }
        int first_num = 0;
        for (int i = 0; i < A.size(); i++) {
            if ((A[i] & mask) != 0) 
                first_num ^= A[i];
        }
        m_res.push_back(first_num);
        m_res.push_back(two_left ^ first_num); 
        return m_res;
    }
};
