class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // Just submit this code, then you will get accepted!
        int carry = 0;
        while (b) {
            // get all carry bits
            carry = a & b;
            // update new a
            a ^= b;
            // update carry for next round
            carry <<= 1;
            b = carry;
        }
        return a;
    }
};
