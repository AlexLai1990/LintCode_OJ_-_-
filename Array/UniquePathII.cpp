class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int row = obstacleGrid.size();
        if (row < 1)
            return 0;
        int col = obstacleGrid[0].size();
        vector<int> m_steps(col, 0);
        for (int i = 0; i < col; i++) {
            if (obstacleGrid[0][i] != 1) {
                m_steps[i] = 1;
            }
            else 
                break;
        }
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (obstacleGrid[i][j] == 1)
                    m_steps[j] = 0;
                else {
                    if (j > 0)
                        m_steps[j] += m_steps[j  - 1];
                }
            }
        }
        return m_steps[col - 1];
    }
};
