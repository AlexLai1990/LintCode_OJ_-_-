class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        int len_1 = word1.length();
        int len_2 = word2.length();
        if (len_1 == 0)
            return len_2;
        if (len_2 == 0)
            return len_1;
        vector<vector<int> > m_dp(len_1 + 1, vector<int> (len_2 + 1, 0));
        for (int i = 1; i <= len_2; i++) {
            m_dp[0][i] = i;
        }
        for (int i = 1; i <= len_1; i++) {
            m_dp[i][0] = i;
        }
        for (int i = 1; i <= len_1; i++) {
            for (int j = 1; j <= len_2; j++) {
                m_dp[i][j] = min(m_dp[i - 1][j], m_dp[i][j - 1]) + 1;
                int add_word = word1[i - 1] == word2[j - 1] ? 
                    m_dp[i - 1][j - 1] : m_dp[i - 1][j - 1] + 1; 
                m_dp[i][j] = min(m_dp[i][j], add_word);
            }
        }
        return m_dp[len_1][len_2];
    }
};

