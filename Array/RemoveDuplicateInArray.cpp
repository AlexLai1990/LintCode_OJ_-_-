class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1)
            return nums.size();
        int size = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[size - 1] != nums[i])
                nums[size++] = nums[i];
            else 
                continue;
        }
        return size;
    }
};
