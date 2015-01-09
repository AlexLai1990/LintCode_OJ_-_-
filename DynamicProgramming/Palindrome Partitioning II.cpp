class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        int s_len = s.length(); 
        if (s_len <= 1)
            return 0;
        vector<vector<bool> > m_set = palindrome_set(s, s_len);
        vector<int> m_dp(s_len + 1, INT_MAX);
        m_dp[0] = -1;
        for (int i = 1; i <= s_len; i++) {
            for (int j = 1; j <= i; j++) {
                if (m_set[i - j][i - 1]) {
                    m_dp[i] = min(m_dp[i], m_dp[i - j] + 1);
                }
            }
        }
        return m_dp[s_len];
    }
    
    vector<vector<bool> > palindrome_set(const string &s, int n) {
        vector<vector<bool> > ret(n, vector<bool> (n, false));
        for (int i = 0; i < n; i++) {
            ret[i][i] = true;
            if (i + 1 < n && s[i] == s[i + 1])
                ret[i][i + 1] = true;
        } 
        for (int i = n - 3; i >= 0; i--) {
            for (int j = n - 1; j > i + 1; j--) {
                ret[i][j] = s[i] == s[j] && ret[i + 1][j - 1];
            }
        }
        return ret;
    }
    
};


