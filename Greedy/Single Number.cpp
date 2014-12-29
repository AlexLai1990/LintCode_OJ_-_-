class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int m_res = 0;
        for (int i = 0; i < A.size(); i++) {
            m_res ^= A[i];
        }
        return m_res;
    }
};

