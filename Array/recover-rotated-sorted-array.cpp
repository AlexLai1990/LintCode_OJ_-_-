#include <vector>

using namespace std;

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1)
            return ;
        int min_index = -1;
        int start = 0, end = nums.size() - 1;
        int mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            // mid < end
            if (mid != start && nums[mid] < nums[end] && nums[mid - 1] > nums[mid]) {
                min_index = mid;
                break;
            }
            else if (nums[mid] < nums[end]) {
                end = mid;
            }
            else 
                start = mid;
        }
        
        if (min_index == -1) {
            min_index = nums[start] < nums[end] ? start : end;
        }
        
        rotate(nums, 0, min_index - 1);
        rotate(nums, min_index, nums.size() - 1);
        rotate(nums, 0, nums.size() - 1);
        return;
    }
    
    void rotate(vector<int> &nums, int start, int end) {
        if (start >= nums.size() || end < 0 ||
            end >= nums.size() || start < 0)
            return;
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }
        return;
    }
};
