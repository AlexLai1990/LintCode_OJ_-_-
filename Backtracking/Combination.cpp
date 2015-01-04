class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > m_res;
        if (n < 0 || k < 0 || k > n)
            return m_res;
        vector<int> path;
        combinationHelper(m_res, path, n, k, 1);
        return m_res;
    }
    
    void combinationHelper(vector<vector<int> > &m_res, vector<int> path, int n, int k, int start) {
        if (path.size() == k) {
            m_res.push_back(path);
        }
        else {
            for (int i = start; i <= n; i++) {
                path.push_back(i);
                combinationHelper(m_res, path, n, k, i + 1);
                path.pop_back();
            }
        }
        return;
    }
};
