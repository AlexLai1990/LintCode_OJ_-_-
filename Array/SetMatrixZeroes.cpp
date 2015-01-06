class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row < 1)
            return;
        int col = matrix[0].size();
        if (col < 1)
            return;
        bool first_row = false, first_col = false;
        for (int i = 0; i < col; i++) {
            if (matrix[0][i] == 0) {
                first_row = true;
                break;
            }
        }
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                first_col = true;
                break;
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < col; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; j++)
                    matrix[j][i] = 0;
            }
        }
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) 
                for (int j = 1; j < col; j++)
                    matrix[i][j] = 0;
        }
        if (first_row)
            for (int i = 0; i < col; i++) 
                matrix[0][i] = 0;
        if (first_col) 
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;
        return;
    }
};
