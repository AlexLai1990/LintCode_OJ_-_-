class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        if (board.size() < 1)
            return false;
        if (word.length() == 0)
            return true;
        int row = board.size();
        int col = board[0].size();
        vector<vector<int> > m_visit(row, vector<int> (col, false));
        
        // DFS all possible position
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (checkExist(board, i, j, word, 0, m_visit))
                    return true;
            }
        }
        return false;
    }
    
    bool checkExist(vector<vector<char> > &board, int x, int y, 
    string word, int count, vector<vector<int> > &visit) {
        if (count == word.length())
            return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }
        if (visit[x][y] == true)
            return false;
        if (board[x][y] != word[count])
            return false;
        
        visit[x][y] = true;
        bool m_ret = checkExist(board, x + 1, y, word, count + 1, visit) ||
                     checkExist(board, x, y + 1, word, count + 1, visit) || 
                     checkExist(board, x - 1, y, word, count + 1, visit) || 
                     checkExist(board, x, y - 1, word, count + 1, visit);     
        visit[x][y] = false;
        
        return m_ret;
    }
};
