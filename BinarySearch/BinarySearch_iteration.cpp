class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if (array.size() < 1)
            return -1;
        int start = 0, end = array.size() - 1;
        int mid = 0;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (array[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (target == array[start])
            return start;
        else if (target == array[end])
            return end;
        return -1;
    }
};
