class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() < 1)
            return false;
        int row = matrix.size();
        int col = matrix[0].size();
        if (col < 1)
            return false;
        int mid = 0, start = 0, end = row * col - 1;
        int cur_row = 0, cur_col = 0, cur_val = INT_MIN;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            cur_row = mid / col;
            cur_col = mid % col;
            cur_val = matrix[cur_row][cur_col];
            if (target == cur_val) 
                return true;
            else if (target < cur_val)
                end = mid;
            else 
                start = mid;
        } 
        if (matrix[start / col][start % col] == target)
            return true;
        else if (matrix[end / col][end % col] == target)
            return true;
        else
            return false;
    }
};

