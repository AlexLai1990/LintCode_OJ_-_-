class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> m_res(2, -1); 
        unordered_map<int, int> m_sum;
        int sum = 0;
        m_sum[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m_sum.find(sum) != m_sum.end()) {
                m_res[0] = m_sum[sum] + 1;
                m_res[1] = i;
                return m_res;
            }
            else {
                m_sum[sum] = i;
            }
        }
        return m_res;
    }
};
