class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x == 0)
            return 0;
        int start = 1;
        int end = x;
        int mid = 0;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (x / mid == mid)
                return mid;
            else if (x / mid < mid)
                end = mid;
            else {
                start = mid;
            }
        }
        if (x / end > end)
            return end;
        else 
            return start;
    }
};
