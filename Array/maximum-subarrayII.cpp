class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here 
        if(nums.size() <= 1) 
            return 0;
        vector<int> prefix_sum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        
        // get one max left subarray in max_sub_left
        // max_sub_left[i] = max sub array from 0 to i - 1, including the ith element.
        vector<int> max_sub_left(prefix_sum.size(), 0);
        max_sub_left[0] = INT_MIN;
        int min_sub = prefix_sum[0];
        for(int i = 1; i < max_sub_left.size(); i++ ){
            if (prefix_sum[i] - min_sub > max_sub_left[i-1])
                max_sub_left[i] = prefix_sum[i] - min_sub;
            else {
                max_sub_left[i] = max_sub_left[i-1];
            }
            if (min_sub > prefix_sum[i])
                min_sub = prefix_sum[i];
        } 
        
    	int two_sub_sum = max_sub_left[max_sub_left.size() - 2] + nums.back();
        int max_sub = prefix_sum.back(); 
        
        for ( int j = max_sub_left.size() - 2; j >= 1 ; j-- ){
            if (max_sub_left[j] + max_sub - prefix_sum[j] > two_sub_sum) {
                two_sub_sum = max_sub_left[j] + max_sub - prefix_sum[j];
            }
            if (max_sub < prefix_sum[j] )
                max_sub = prefix_sum[j];
        }
        
        return two_sub_sum;
    }
};

