class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int> > permute(vector<int> nums) { 
	    if (nums.size() == 0)
	        return m_ret;
		permutator(nums, 0);
		return m_ret;
	}

	void permutator(vector<int>& nums, int cur_index){
		if (nums.size() == cur_index){
			m_ret.push_back(m_path);
		}
		else {
			for (int i = cur_index; i < nums.size(); i++){
				m_path.push_back(nums[i]);
				swap(nums[cur_index], nums[i]);
				permutator(nums, cur_index + 1);
				swap(nums[cur_index], nums[i]);
				m_path.pop_back();
			}
		}
	}

private:
	vector<int> m_path;
	vector<vector<int> > m_ret;
};