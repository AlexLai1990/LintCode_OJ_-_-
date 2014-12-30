class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        vector<vector<string> > m_res;
        if (s.length() < 1)
            return m_res;
        vector<string> m_path;
        partitionHelper(s, m_res, m_path, 0);
        return m_res;
    }
    
    void partitionHelper(const string &s, vector<vector<string> > &m_res, 
        vector<string> &m_path, int start) {
        if (start == s.length()) {
            m_res.push_back(m_path);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                string m_cut = s.substr(start, i - start + 1);
                m_path.push_back(m_cut);
                partitionHelper(s, m_res, m_path, i + 1);
                m_path.pop_back();
            }
        }
        return;
    }
    
    bool isPalindrome(const string &s, int start, int end) {
        int len = s.length();
        if (len <= start || len <= end)
            return false;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
