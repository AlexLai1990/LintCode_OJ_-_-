class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if (row < 1)
            return 0;
        int col = matrix[0].size();
        if (col < 1)
            return 0;
        int count = 0;
        for (int j = col - 1, i = 0; j >= 0 && i < row; ) { 
            if (matrix[i][j] == target) {
                count++;
                i++;
            }
            else if (matrix[i][j] < target) {
                i++;
            }
            else {
                j--;
            } 
        }
        return count;
    }
};