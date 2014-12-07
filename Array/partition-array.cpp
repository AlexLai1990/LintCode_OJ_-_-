class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        // here k is the value not the position,
        // so we don't need use partition way in quicksort
        int m_count = 0;
        if (nums.size() < 1)
            return m_count;
        int start = 0, end = nums.size() -1;
        int i = start;
        while (i <= end) {
            if (nums[i] < k) {
                swap(nums[i++], nums[start++]);
            }
            else if (nums[i] == k) {
                i++;
            }
            else {
                // because we scan from left to right, 
                // start is sorted, we need to check this new i which from old end.
                swap(nums[i], nums[end--]);
            }
        }
        i = 0;
        while (i < nums.size() && nums[i] < k) {
            m_count++;
            i++;
        }
        return m_count;
    }
};
