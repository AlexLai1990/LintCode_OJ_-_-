int threeSumClosest(vector<int> nums, int target) {
    // write your code here
    int m_dif = INT_MAX;
    if (nums.size() < 3)
        return m_dif;
    sort(nums.begin(), nums.end());
    int m_res;
    int prev_i, prev_j, prev_k;
    int j, k;
    int temp_res;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i != 0 && nums[i] == prev_i)
            continue;
        prev_i = nums[i];
        j = i + 1;
        k = nums.size() - 1;
        while (j < k) {
            temp_res = nums[i] + nums[j] + nums[k]; 
            prev_j = nums[j];
            prev_k = nums[k];
            if (temp_res == target)
                return temp_res;
            else if (temp_res < target) {
                j++;
                while (nums[j] == prev_j && j < nums.size() - 1)
                    j++;
            }
            else {
                k--;
                while (nums[k] == prev_k && k > 1)
                    k--;
            }
            int temp_dif = abs(temp_res - target);
            if (temp_dif < m_dif) {
                m_res = temp_res;
                m_dif = temp_dif;
            }
        }
    }
    return m_res;
}