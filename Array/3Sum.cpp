vector<vector<int> > threeSum(vector<int> &nums) {
    // write your code here
    vector<vector<int> > m_ret;
    if (nums.size() < 2) {
        return m_ret;
    }
    sort(nums.begin(), nums.end());
    int prev_i, prev_left, prev_right;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i != 0 && nums[i] == prev_i) {
            continue;
        }
        prev_i = nums[i];
        int left = i + 1, right = nums.size() - 1; 
            
        int temp_result;
        while (left < right) { 
            prev_left = nums[left];
            prev_right = nums[right];     
            temp_result = nums[i] + nums[left] + nums[right];
            if (temp_result == 0) {
                vector<int> temp(3, -1);
                temp[0] = nums[i];
                temp[1] = nums[left++];
                temp[2] = nums[right--];
                m_ret.push_back(temp); 
                while(nums[right] == prev_right)
	                right--;
                while(nums[left] == prev_left)
	                left++;
            }
            else if (temp_result < 0) { 
                left++;
                while(nums[left] == prev_left)
	                left++;
            }
            else {
                right--;
                while(nums[right] == prev_right)
	                right--; 
            }
        }
    }
    
    return m_ret;
}