class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.length() != t.length())
            return false;
        vector<int> m_count(256,0);
        for (int i = 0; i < s.length(); i++) {
            m_count[s[i] - '\0']++;
            m_count[t[i] - '\0']--;
        }
        for (int i = 0; i < m_count.size(); i++) {
            if (m_count[i] != 0)
                return false;
        }
        return true;
    } 
};
