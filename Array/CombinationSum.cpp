class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > m_ret;
        if (candidates.size() == 0)
            return m_ret;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        combinationSumHelper(candidates, curr, 0, target, 0, m_ret);
        return m_ret;
    }
    
    void combinationSumHelper(vector<int> &candidates, vector<int> curr, int start_index,
                                int target, int curr_sum, vector<vector<int> >&m_ret) {
        if (curr_sum > target)
            return ;
        if (curr_sum == target) {
            m_ret.push_back(curr);
            return;
        }
        
        for (int i = start_index; i < candidates.size(); i++) {
            int temp_curr_sum = curr_sum + candidates[i];
            curr.push_back(candidates[i]);
            combinationSumHelper(candidates, curr, i, target, temp_curr_sum, m_ret); 
            curr.pop_back();
        }
        return;
    }
};
