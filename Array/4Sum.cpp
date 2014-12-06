vector<vector<int> > fourSum(vector<int> nums, int target) {
    // write your code here
    vector<vector<int> > m_ret;
    if (nums.size() < 4) {
        return m_ret;
    }
    sort(nums.begin(), nums.end() );
    int i, j;
    set<vector<int> > m_set;
    vector<int> m_temp;
    for (i = 0; i < nums.size() - 3; i++) {
        for (j = i + 1; j <nums.size() - 2; j++) {
            int left = j + 1; 
            int right = nums.size() - 1;
            int temp_left = target - nums[i] - nums[j];
            int test;
            while (left < right) {
                test = nums[left] + nums[right];
                if (temp_left == test) {
                    m_temp.clear();
                    m_temp.push_back(nums[i]);
                    m_temp.push_back(nums[j]);
                    m_temp.push_back(nums[left]);
                    m_temp.push_back(nums[right]);
                    m_set.insert(m_temp);
                    left++;
                    right--; 
                } 
                else if (temp_left < test) {
                    right--;
                }
                else if (temp_left > test) {
                    left++;
                }
            }
        }
    }
    for (auto item : m_set) {
        m_ret.push_back(item);
    }
    return m_ret;
}