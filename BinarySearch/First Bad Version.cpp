/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int start = 1;
        int end = n;
        int mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (!VersionControl::isBadVersion(mid)) 
                start = mid;
            else 
                end = mid;
        }
        if (VersionControl::isBadVersion(start))
            return start;
        else if (VersionControl::isBadVersion(end))
            return end;
        else 
            return -1;
    }
};

