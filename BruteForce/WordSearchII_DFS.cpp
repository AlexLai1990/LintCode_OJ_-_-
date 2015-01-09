class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) { 
        vector<string> m_res;
        int row = board.size();
        if (row < 1)
            return m_res;
        int col = board[0].size(); 
        vector<vector<bool> > visited(row, vector<bool> (col, false));
        for (int i = 0; i < words.size(); i++) {
            for (int x = 0; x < row; x++) {
                int y = 0;
                for (; y < col; y++) {
                    if (wordSearchIIHelper(board, words[i], x, y, 0, visited)) {
                        m_res.push_back(words[i]);
                        break;
                    }
                }
                if (y < col)
                    break;
            }
        } 
        return m_res;
    }
    
    bool wordSearchIIHelper(vector<vector<char> > &board, const string &word, 
        int x, int y, int count, vector<vector<bool> > &visited) {
        if (count == word.length())
            return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y])
            return false; 
        if (word[count] != board[x][y])
            return false;
        visited[x][y] = true;
        bool m_ret = wordSearchIIHelper(board, word, x + 1, y, count + 1, visited) ||
                     wordSearchIIHelper(board, word, x, y + 1, count + 1, visited) || 
                     wordSearchIIHelper(board, word, x - 1, y,count + 1, visited) || 
                     wordSearchIIHelper(board, word, x, y - 1, count + 1, visited);  
        visited[x][y] = false;
        return m_ret;
    }
};
