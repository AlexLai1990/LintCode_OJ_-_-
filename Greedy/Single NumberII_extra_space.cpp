class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        vector<int> m_count(32,0);
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j <= 31; j++) {
                if ((A[i] & (1 << j)) != 0)
                    m_count[j]++;
            }
        }
        int m_res = 0;
        for (int i = 0; i < 32; i++) {
            m_res *= 2;
            if (m_count[31 - i] % 3 != 0)
                m_res += m_count[31 - i] % 3;
        }
        return m_res;
    }
};
