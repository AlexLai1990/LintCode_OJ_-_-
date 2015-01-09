class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (p == NULL)
            return s == NULL;
        if (*p == '\0')
            return *s == '\0';
        if (*(p + 1) != '*') {
            // next cannot be *, if p == ',', s == '\0', p has one char left.
            if (*s == *p || (*p == '.' && *s != '\0' ))
                return isMatch(s + 1, p + 1);
            else 
                return false;
        }
        else {
            while (*s == *p || (*p == '.' && *s != '\0' )) {
                if (isMatch(s, p + 2))
                    return true;
                s++;
            }
            return isMatch(s, p + 2);
        }
    }
};
