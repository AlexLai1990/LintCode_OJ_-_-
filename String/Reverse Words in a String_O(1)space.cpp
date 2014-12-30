
class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) { 
        int len = s.length();
        if (len == 0 || len == 1) 
            return s;
        int start = 0, m_start = 0;
        while (start < len && s[start] == ' ') 
            start++;
        m_start = start;
            
        int temp_end = start;
        while (start < len) {
            while (temp_end < len && s[temp_end] != ' ') 
                temp_end++;
            reverseWord(s, start, temp_end - 1);
            // update new start
    		while (temp_end < len && s[temp_end] == ' ')
    			temp_end++;
    		start = temp_end;
        }
        start--;
        while (start >= 0 && s[start] == ' ') 
            start--;
        s = s.substr(m_start, start - m_start + 1);
        reverseWord(s, 0, s.length() - 1);
        return s;
    } 
    
    void reverseWord(string &s, int start, int end) {
        int len = s.length();
        if (len <= start || len <= end || end < start)
            return;
        while (start < end) {
            swap(s[start++], s[end--]);
        }
        return;
    }
};
