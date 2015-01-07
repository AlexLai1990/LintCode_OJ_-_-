class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int start = 0;
        int end = num.size() - 1;
        int mid = 0;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (num[start] < num[end])
                return num[start];
            else if (num[mid - 1] > num[mid] && num[mid] < num[mid + 1])
                return num[mid];
            else if (num[mid] > num[end])
                start = mid;
            else 
                end = mid;
        }
        return min(num[start], num[end]);
    }
};
