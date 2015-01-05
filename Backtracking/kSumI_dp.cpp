class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */ 
    
    int kSum(vector<int> A, int k, int target) { 
        int len = A.size();
        if (len < k || k < 1)
            return 0;
        vector<vector<int> > m_count(k + 1, vector<int> (target + 1, 0));
        m_count[0][0] = 1;
        for (int i = 1; i <= len; i++) {
            // update using num digits first than using num-- digits
            for (int num = min(i, k); num > 0; num--) {
                for (int t = target; t >= A[i - 1]; t--) {
                    m_count[num][t] += m_count[num - 1][t - A[i - 1]];
                }
            }
        }
        return m_count[k][target];
    }
};