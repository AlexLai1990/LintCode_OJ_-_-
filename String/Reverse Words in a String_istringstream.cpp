#include <sstream>

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        istringstream ss(s);
        string word = "";
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        
        string m_res = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            m_res += words[i] + " ";
        }
        if (m_res.length() > 0)
            m_res.pop_back();
        return m_res;
    } 
};
