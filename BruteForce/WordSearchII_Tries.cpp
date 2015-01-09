
class TrieNode {
public:
    TrieNode () {
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
    void addNode(string str, int index) { 
        if (index == str.length()) {
            isEnd = true;
            return;
        }
        if (children[str[index] - 'a'] == NULL) {
            children[str[index] - 'a'] = new TrieNode();
        }
        children[str[index] - 'a'] ->addNode(str, index + 1);
        return ;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; i++) { 
            if (children[i] != NULL) {
                delete children[i];
                children[i] = NULL;
            }
        }
    }
    TrieNode *children[26];
    bool isEnd;
};

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
        TrieNode *m_root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            m_root->addNode(words[i], 0);
        }
        vector<vector<bool> > visited(row, vector<bool> (col, false));
        unordered_set<string> m_set;
        string word;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                wordSearchIIHelper(board, word, i, j, m_root, visited, m_set);
            }
        }
        for (auto item: m_set)
            m_res.push_back(item);
        return m_res;
    } 
    
    void wordSearchIIHelper(const vector<vector<char> > &board, string word, 
        int x, int y, TrieNode *root, vector<vector<bool> > &visited, unordered_set<string> &m_set) {
        if (root != NULL && root->isEnd)
            m_set.insert(word);
        if (!root || x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y])
            return;
            
        char curr_char = board[x][y];
        visited[x][y] = true;
        // check current existence
        TrieNode *curr = root->children[curr_char - 'a'];
        word += curr_char;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            wordSearchIIHelper(board, word, x+dx[i], y+dy[i], curr, visited, m_set);
        }
        visited[x][y] = false;
        return;
    } 
};

