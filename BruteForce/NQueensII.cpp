class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        int count = 0;
        if (n < 1)
            return count;
        int *columns = new int[n];
        memset(columns, -1, sizeof(columns));
        NQueensHelper(columns, count, 0, n);
        return count;
    }
    
    void NQueensHelper(int *columns, int &count, int row, int n) {
        if (row == n)
            count++;
        else {
            for (int i = 0; i < n; i++) {
                if (checkValid(columns, row, i)) {
                    columns[row] = i;
                    NQueensHelper(columns, count, row + 1, n); 
                    columns[row] = -1;
                }
            }
        }
        return;
    }
    
    bool checkValid(int *columns, int row, int col) {
        for (int i = 0; i < row; i++) {
            int temp_col = columns[i];
            if (temp_col == col)
                return false;
            int diff_y = abs(col - temp_col);
            int diff_x = row - i;
            if (diff_y == diff_x)
                return false;
        }
        return true;
    }
};

