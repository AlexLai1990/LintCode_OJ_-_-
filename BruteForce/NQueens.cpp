class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > m_res;
        if (n < 1)
            return m_res;
        int *columns = new int[n];
        memset(columns, -1, sizeof(columns));
        vector<string> m_path;
        solveNQueensHelper(m_res, m_path, columns, 0, n);
        delete columns;
        return m_res;
    }
    
    // dfs row by row
    void solveNQueensHelper(vector<vector<string> > &m_res, vector<string> m_path,
        int *columns, int row, int n) {
        if (row == n) {
            m_res.push_back(m_path);
        }
        else {
            // check from col 1 to col n-1
            for (int i = 0; i < n; i++) {
                if (checkValid(columns, row, i)) {
                    string curr_row(n, '.');
                    curr_row[i] = 'Q';
                    columns[row] = i;
                    m_path.push_back(curr_row);
                    solveNQueensHelper(m_res, m_path, columns, row + 1, n); 
                    m_path.pop_back();
                    columns[row] = -1;
                    curr_row[i] = '.';
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
            int diff_x = abs(col - temp_col);
            int diff_y = row - i;
            if (diff_x == diff_y)
                return false;
        }
        return true;
    }
};

