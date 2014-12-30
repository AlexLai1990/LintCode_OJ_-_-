class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        if (str == "")
            return true;
        vector<bool> m_letter(256, false);
        int len = str.length();
        for (int i = 0; i < len; i++) {
            if (m_letter[str[i]-'\0'])
                return false;
            else 
                m_letter[str[i]-'\0'] = true;
        }
        return true;
    }
};
