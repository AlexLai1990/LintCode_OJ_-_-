class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        if (A.length() == 0)
            return A;
        int len = A.length();
        offset %= len;
        int end = len - 1 - offset;
        rotatehelper(A, 0, end);
        rotatehelper(A, end + 1, len - 1);
        rotatehelper(A, 0, len - 1);
        return A;
    }
    
    void rotatehelper(string &str, int start, int end) {
        if (end <= start || end >= str.length() || start < 0)
            return; 
        while (start < end) {
            swap(str[start++], str[end--]);
        }
        return;
    }
};
