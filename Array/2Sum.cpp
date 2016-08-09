vector<int> twoSum(vector<int> &nums, int target) {
    // write your code here
    vector<int> m_ret(2,-1);
    if (nums.size() < 1)
        return m_ret;
    unordered_map<int,int> m_dict;
    for (int i = 0; i < nums.size(); i++) {
        m_dict[nums[i]] = i + 1;
    }
    int num_left = 0;
    for (int i = 0; i < nums.size(); i++) {
        num_left = target - nums[i];
        if (m_dict.find(num_left) != m_dict.end()) {
            m_ret[0] = i + 1;
            m_ret[1] = m_dict[num_left];
            break;
        } 
    }
    return m_rets;
} 