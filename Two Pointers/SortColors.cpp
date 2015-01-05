class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        if (nums.size() == 0)
            return ;
        int zero_index = 0;
        int two_index = nums.size() - 1;
        for (int i = 0; i <= two_index; ) {
            if (nums[i] == 0) {
                swap(nums[zero_index++], nums[i++]);
            }
            else if (nums[i] == 2) {
                swap(nums[two_index--], nums[i]);
            }
            else {
                i++;
            }
        }
        return;
    }
};
