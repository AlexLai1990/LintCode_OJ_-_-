class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        vector<int> m_res = nums;
        if (nums.size() < 1)
            return m_res;
        int swap_left = -1, swap_right = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            // find the first peak from right 
            if(nums[i] > nums[i + 1]) {
                swap_left = i;
                // find the fisrt smaller number from peak to the end
                for (int j = nums.size() - 1; j > swap_left; j--) {
                    if (nums[j] < nums[i]) {
                        swap_right = j;
                        break;
                    }
                }
                break;
            }
        }
        if (swap_left == -1) {
            sort(m_res.begin(), m_res.end(), std::greater<int>());
            return m_res;
        }
        swap(m_res[swap_left], m_res[swap_right]);
        sort(m_res.begin() + swap_left + 1, m_res.end(), std::greater<int>());
        return m_res;
    }
};
