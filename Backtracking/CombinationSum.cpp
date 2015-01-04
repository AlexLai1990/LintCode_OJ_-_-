class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > m_res;
        if (candidates.size() == 0)
            return m_res;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        combinationSumHelper(candidates, curr, 0, target, m_res);
        return m_res;
    }
    
    void combinationSumHelper(vector<int> &candidates, vector<int> curr, int start_index,
                                int curr_left, vector<vector<int> >&m_res) {
        if (curr_left < 0)
            return ;
        if (curr_left == 0) {
            m_res.push_back(curr);
            return;
        }
        
        for (int i = start_index; i < candidates.size(); i++) {
            int temp_curr_left = curr_left - candidates[i];
            curr.push_back(candidates[i]);
            combinationSumHelper(candidates, curr, i, temp_curr_left, m_res); 
            curr.pop_back();
        }
        return;
    }
};
