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
        vector<int> m_len(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            // j stands for length
            for (int j = 1; j <= i; j++) {
                if (nums[i] >= nums[i - j] && m_len[i - j] + 1 > m_len[i])
                    m_len[i] = m_len[i - j] + 1;
            }
        }
        int m_max_len = INT_MIN;
        for (int i = 0; i < m_len.size(); i++) {
            if (m_max_len < m_len[i])
                m_max_len = m_len[i];
        }
        return m_max_len;
    }
};

