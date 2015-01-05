class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) { 
        int len_s1 = s1.length();
        int len_s2 = s2.length();
        int len_s3 = s3.length();
        if (len_s1 + len_s2 != len_s3)
            return false;
        vector<vector<bool> > dp(len_s2 + 1, vector<bool> (len_s1 +1 , false));
        dp[0][0] = true;
        for (int i = 1; i <= len_s1; i++) {
            if (s1[i - 1] == s3[i - 1])
                dp[0][i] = true;
        }
        for (int i = 1; i <= len_s2; i++) {
            if (s2[i - 1] == s3[i - 1])
                dp[i][0] = true;
        }
        for (int i = 1; i <= len_s2; i++) {
            for (int j = 1; j <= len_s1; j++) {
                dp[i][j] = (dp[i - 1][j] && (s2[i - 1] == s3[i + j -1])) || 
                    (dp[i][j - 1] && (s1[j - 1] == s3[i + j - 1]));
            }
        }
        return dp[len_s2][len_s1];
    }
};
