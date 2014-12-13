class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n < 3)
            return n;
        int one_step = 1; int two_step = 2;
        int total = 0;
        for (int i = 3; i <= n; i++) {
            total = one_step + two_step;
            one_step = two_step;
            two_step = total;
        }
        return total;
    }
};

