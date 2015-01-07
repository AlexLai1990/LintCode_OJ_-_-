class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row < 1)
            return;
        int col = matrix[0].size();
        if (col < 1)
            return;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col - i; j++) {
                swap(matrix[i][j], matrix[col - j - 1][row - i - 1]);
            }
        }
        for (int i = 0; i < row / 2; i++) {
            for (int j = 0; j < col; j++) 
                swap(matrix[i][j], matrix[row - i - 1][j]);
        }
        return;
    }
};
