class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int row = grid.size();
        if (row < 1)
            return 0;
        int col = grid[0].size();
        vector<int> dp(col, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (j == 0) {
                    dp[0] += grid[i][j];
                }
                else {
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[col - 1];
    }
};

