class Solution {
public:    
// String T needs to be all matched in string S


    int numDistinct(string &S, string &T) { 
        int s_len = S.length();
        int t_len = T.length();
        vector<vector<int> > m_dp(t_len + 1, vector<int> (s_len + 1, 0));
        for (int i = 0; i <= s_len; i++) 
            m_dp[0][i] = 1;
        for (int i = 1; i <= t_len; i++) {
            for (int j = 1; j <= s_len; j++) {
                m_dp[i][j] = T[i - 1] == S[j - 1] ? 
                    m_dp[i][j - 1] + m_dp[i - 1][j - 1] : m_dp[i][j - 1];
            }
        }
        return m_dp[t_len][s_len];
    }
};

