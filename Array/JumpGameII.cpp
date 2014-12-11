class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        if (A.size() == 0)
            return 0;
        if (A.size() == 1)
            return 1;
        int steps = 0;
        int currstep_max = 0, max_reach = 0, temp_reach = 0;
        int i = 0;
        while (i <= currstep_max) {
            if (i > max_reach) {
                max_reach = currstep_max;
                steps++;
            }
            temp_reach = i + A[i];
            if (temp_reach >= A.size() - 1) {
                steps++;
                return steps;
            }
            if (temp_reach > currstep_max)
                currstep_max = temp_reach;
            i++;
        }
        
        return -1;
    }
};
