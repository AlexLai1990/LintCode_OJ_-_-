class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
    	if (nums.size() < 2)
    		return 0;
    	vector<int> pre_sum(nums.size() + 1, 0);
    	for (int i = 1; i < pre_sum.size(); i++) {
    		pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
    	}
    	vector<int> pos_sum(nums.size() + 1, 0);
    	for (int i = pre_sum.size() - 2; i >= 0; i--) {
    		pos_sum[i] = pos_sum[i + 1] + nums[i];
    	}
    	vector<int> left_max(pre_sum.size(), 0);
    	vector<int> left_min(pre_sum.size(), 0);
    	vector<int> right_max(nums.size(), 0);
    	vector<int> right_min(nums.size(), 0);
    	left_max[0] = INT_MIN;
    	int curr_min = 0;
    	for (int i = 1; i < left_max.size(); i++) {
    		int temp = pre_sum[i] - curr_min;
    		left_max[i] = temp > left_max[i - 1] ? temp : left_max[i - 1];
    		left_max[i] = max(left_max[i], nums[i - 1]);
    		if (left_max[i] < curr_min)
    			curr_min = left_max[i];
    		if (curr_min > pre_sum[i])
    			curr_min = pre_sum[i];
    	}
    	int curr_max = 0;
    	right_min[right_min.size() - 1] = INT_MAX;
    	for (int i = right_min.size() - 2; i >= 0; i--) {
    		int temp = pos_sum[i + 1] - curr_max;
    		right_min[i] = temp < right_min[i + 1] ? temp : right_min[i + 1];
    		right_min[i] = min(right_min[i], nums[i + 1]);
    		if (right_min[i] > curr_max)
    			curr_max = right_min[i];
    		if (curr_max < pos_sum[i + 1])
    			curr_max = pos_sum[i + 1];
    	}
    	curr_min = 0;
    	right_max[right_min.size() - 1] = INT_MIN;
    	for (int i = right_max.size() - 2; i >= 0; i--) {
    		int temp = pos_sum[i + 1] - curr_min;
    		right_max[i] = temp > right_max[i + 1] ? temp : right_max[i + 1];
    		right_max[i] = max(right_max[i], nums[i + 1]);
    		if (curr_min > right_max[i])
    			curr_min = right_max[i];
    		if (curr_min > pos_sum[i + 1])
    			curr_min = pos_sum[i + 1];
    	}
    	curr_max = 0;
    	left_min[0] = INT_MAX;
    	for (int i = 1; i < left_min.size(); i++) {
    		int temp = pre_sum[i] - curr_max;
    		left_min[i] = temp < left_min[i - 1] ? temp : left_min[i - 1];
    		left_min[i] = min(left_min[i], nums[i - 1]);
    		if (curr_max < left_min[i])
    			curr_max = left_min[i]; 
    		if (curr_max < pre_sum[i])
    			curr_max = pre_sum[i];
    	}
    	// because each subarray needs to have at lease one number
    	int m_res = 0;
    	for (int i = 0; i < right_max.size() - 1; i++) {
    		m_res = max(m_res, 
    		max(abs(left_max[i + 1] - right_min[i]), abs(right_max[i] - left_min[i + 1])) );
    	}
    	return m_res;
    }
};

