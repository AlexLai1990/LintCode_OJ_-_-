class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if (row < 1)
            return 0;
        vector<int> m_path(row, 0); 
        vector<int> m_temp = m_path;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j <= i ; j++) {
                if (j == 0)
                    m_path[0] = m_temp[0] + triangle[i][j];
                else if (j == i) {
                    m_path[j] = m_temp[j - 1] + triangle[i][j];
                }
                else {
                    m_path[j] = min(m_temp[j - 1], m_temp[j]) + triangle[i][j];
                }
            }
            m_temp = m_path;
        }
        int m_min = INT_MAX;
        for (int i = 0; i < m_path.size(); i++) {
            if (m_min > m_path[i])
                m_min = m_path[i];
        }
        return m_min;
    }
};

