class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) { 
        vector<vector<int> > m_res;
        vector<int> path;
        kSumIIHelper(A, m_res, path, k, 0, target, 0);
        return m_res;
    }
    
    void kSumIIHelper(const vector<int> &A, vector<vector<int> > &m_res, 
        vector<int> path, int k, int count, int left, int start) {
        if (count == k && left == 0)
            m_res.push_back(path);
        else if (count > k || left < 0)
            return;
        else {
            for (int i = start; i < A.size(); i++) {
                path.push_back(A[i]); 
                kSumIIHelper(A, m_res, path, k, count + 1, left - A[i], i + 1);
                path.pop_back();
            }
        }
        return;
    }
};

