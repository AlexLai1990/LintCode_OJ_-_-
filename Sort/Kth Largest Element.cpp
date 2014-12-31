class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) { 
        if (k < 1 || k > nums.size())
            return -1;
        return findKthHelper(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
    
    int findKthHelper(vector<int> &nums, int start, int end, int k) { 
        int mid = start + (end - start)/2;
        int pivot = nums[mid];
        swap(nums[mid], nums[start]);
        int left = start;
        int right = end;
        while (left <= right) {
            while (left <= right && nums[left] <= pivot)
                left++;
            while (left <= right && nums[right] >= pivot)
                right--;
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
        // right's position is right
        swap(nums[start], nums[right]);
        if (right + 1 == k)
            return nums[right];
        else if (right + 1 < k) 
        // because we check found by index, so we keep k as argument
            return findKthHelper(nums, right + 1, nums.size() - 1, k);
        else 
            return findKthHelper(nums, start, right - 1, k);
    } 
};
