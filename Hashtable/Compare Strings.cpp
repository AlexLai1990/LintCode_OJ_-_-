class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int len_a = A.length();
        int len_b = B.length();
        if (len_b > len_a)
            return false;
        vector<int> m_letter(26, 0); 
        for (int i = 0; i < len_a; i++) {
            m_letter[A[i] - 'A']++;
        }
        for (int i = 0; i < len_b; i++) {
            m_letter[B[i] - 'A']--;
        }
        for (int i = 0; i < 26; i++) {
            if (m_letter[i] < 0)
                return false;
        }
        return true;
    }
};

