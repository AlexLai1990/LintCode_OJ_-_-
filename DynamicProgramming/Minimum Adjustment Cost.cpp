class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) { 
        if (target < 0 || A.size() < 2)
            return 0;
        int n = A.size();
        vector<vector<int> > m_adj(n, vector<int> (101, INT_MAX));
        for (int i = 1; i < 101; i++) {
            m_adj[0][i] = abs(A[0] - i);
        }
        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < 101; j++) {
                // cannot reach
                if (m_adj[i - 1][j] == INT_MAX)
                    continue;
                for (int k = max(0, j - target); k <= 100 && k <= j + target; k++) {
                    m_adj[i][k] = min(m_adj[i][k], m_adj[i - 1][j] + abs(A[i] - k) ); 
                }
            }
        }
        return *min_element(m_adj[n - 1].begin(), m_adj[n - 1].end());
    }
};
