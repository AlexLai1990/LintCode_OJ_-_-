class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) { 
        int len_a = A.length();
        int len_b = B.length();
        vector<vector<int> > m_state(len_b + 1, vector<int> (len_a + 1, 0)); 
        int max_len = 0;
        for (int i = 1; i <= len_b; i++) {
            for (int j = 1; j <= len_a; j++) {
                if (B[i - 1] == A[j - 1]) { 
                    m_state[i][j] = m_state[i-1][j-1] + 1;
                    if (max_len < m_state[i][j])
                        max_len = m_state[i][j];
                }
                else {
                    m_state[i][j] = 0;
                }
            }
        }
        return max_len;
    }
};

