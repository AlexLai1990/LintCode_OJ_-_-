class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        int a_len = A.size();
        int b_len = B.size();
        vector<vector<int> > common_count(a_len + 1, vector<int> (b_len + 1, 0));
        for (int i = 1; i <= b_len; i++) {
            for (int j = 1; j <= a_len; j++) {
                int temp_max_len = 0;
                if (B[i - 1] == A[j - 1]) {
                    temp_max_len = common_count[i - 1][j - 1] + 1;
                }
                common_count[i][j] = max(temp_max_len, max(common_count[i - 1][j], common_count[i][j - 1]));
            }
        }
        return common_count[b_len][a_len];
    }
};