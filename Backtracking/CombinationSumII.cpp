class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) { 
        vector<vector<int> > m_res;
        if (num.size() == 0)
            return m_res;
        sort(num.begin(), num.end());
        vector<int> curr;
        combinationSumHelper(num, curr, 0, target, m_res);
        return m_res;
    }
    
    void combinationSumHelper(vector<int> &num, vector<int> curr, int start_index,
                                int curr_left, vector<vector<int> >&m_res) {
        if (curr_left < 0) 
            return;
        if (curr_left == 0) {
            m_res.push_back(curr);
            return;
        } 
        for (int i = start_index; i < num.size(); i++) {
            // skip the duplicate numbers
            while (i != start_index && i < num.size() && num[i] == num[i - 1])
                i++;
            if (i < num.size()) {
                int temp_curr_left = curr_left - num[i];
                curr.push_back(num[i]);
                combinationSumHelper(num, curr, i + 1, temp_curr_left, m_res);
                curr.pop_back();
            }
        }
        return;                        
    }
};
