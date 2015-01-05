class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) { 
        int start = 0;
        for (int i = 0; i < letters.length(); i++) {
            if (letters[i] >= 'a') {
                swap(letters[start++], letters[i]);
            }
        }
        return;
    }
};

