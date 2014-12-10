#include <vector>

using namespace std;


class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here 
        if (nums.size() == 0)
            return  0;
        int m_res = INT_MIN;
        int temp_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            temp_sum += nums[i];
            
            if (temp_sum > m_res)
                m_res = temp_sum;
                
            if (temp_sum < 0)
                temp_sum = 0;  
        } 
        return m_res;
    }
};

