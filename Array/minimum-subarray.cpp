#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 1)
            return nums[0]; 
            
        // be careful about initialization.
        vector<int> m_sum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            m_sum[i] = m_sum[i - 1] + nums[i - 1];
        }
        int m_min_res = INT_MAX;
        for (int right = 1; right <= nums.size(); right++) { 
            for (int left = 0; left < right; left++) {
                int cur_sum = m_sum[right] - m_sum[left];
                if (cur_sum < m_min_res)
                    m_min_res = cur_sum;
            }
        }
        
        return m_min_res;
    }
};

