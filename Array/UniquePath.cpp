class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m == 1 || n == 1)
            return 1;
        vector<int> m_steps(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                m_steps[j] = m_steps[j - 1] + m_steps[j];
            }
        }
        return m_steps[n - 1];
    }
};

