class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
     
     // more than 1/k need to check hashtable each time size() will come to k+1.
    int majorityNumber(vector<int> nums, int k) {
        if (nums.size() < 1 || k < 1 || k > nums.size())
            return -1;
            
        unordered_map<int, int> m_counts;
        int m_ret, m_count = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (m_counts.find(nums[i]) == m_counts.end()) {
                if (m_counts.size() < k - 1) {
                    m_counts[nums[i]]++;
                }
                else if (m_counts.size() == k - 1) {
                    for (auto it = m_counts.begin(); it != m_counts.end();) {
                        if (--(it->second) == 0) {
                            auto the_next = it;
                            the_next++;
                            m_counts.erase(it);
                            it = the_next;
                        }
                        else {
                            it++;
                        }
                    }
                }
            }
            else {
                m_counts[nums[i]]++;
            }
        }
        
        for (auto it = m_counts.begin(); it != m_counts.end(); it++) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (it->first == nums[i])
                    count++;
            }
            if (m_count < count) {
                m_count = count;
                m_ret = it->first;
            }
        }
        return m_ret;
    }
};

