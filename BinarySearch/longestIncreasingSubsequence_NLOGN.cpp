class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if (nums.size() < 1)
            return 0;
        vector<int> m_inc(1, nums[0]);
        int insertPos = 0;
        for (int i = 1; i < nums.size(); i++) {
            insertPos = findInsertPos(m_inc, nums[i]);
            if (insertPos >= m_inc.size())
                m_inc.push_back(nums[i]);
            else 
                m_inc[insertPos] = nums[i];
        }
        return m_inc.size();
    }
    
    // find the last element that is not larger than target 
    int findInsertPos(vector<int> &num_list, int num) {
        if (num_list.size() < 1)
            return 0;
        int start = 0;
        int end = num_list.size() - 1;
        int mid = 0;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (num_list[mid] <= num)
                start = mid;
            else 
                end = mid;
        }
        if (num_list[end] <= num)
            return end + 1;
        else if (num_list[start] <= num)
		    return start + 1;
	    else if (num_list[start] > num)
            return start; 
    }
};

