class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 2)
            return nums.size();
        int size = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[size - 2] != nums[i]) {
                nums[size++] = nums[i];
            }
            else
                continue;
        }
        return size;
    }
};
