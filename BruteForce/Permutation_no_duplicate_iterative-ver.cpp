
class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int> > permute(vector<int> nums) { 
	    if (nums.size() == 0) 
	        return m_ret;
	    vector<int> origin = nums;
	    m_ret.push_back(nums);
	    m_permute = nextPermuation(nums);
	    while (m_permute != origin) {
	        m_ret.push_back(m_permute);
	        m_permute = nextPermuation(nums);
	    }
	    return m_ret;
	}
	
	vector<int> nextPermuation(vector<int> &nums) {
        vector<int> &m_res = nums;
        if (nums.size() == 0)
            return m_res;
        int index_swap_left = nums.size();
        int index_swap_right = nums.size();
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index_swap_left = i;
                for (int j = nums.size() - 1; j > i ; j--) {
                    if (nums[j] > nums[i]) {
                        index_swap_right = j;
                        break;
                    }
                }
                break;
            }
        }
        if (index_swap_left == nums.size()) {
            sort(m_res.begin(), m_res.end());
            return m_res;
        }
        swap(m_res[index_swap_left], m_res[index_swap_right]);
        sort(m_res.begin() + index_swap_left + 1, m_res.end());
        return m_res;
    }  

private:
	vector<int> m_permute;
	vector<vector<int> > m_ret;
};