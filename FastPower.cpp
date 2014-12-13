class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (n == 0 && b != 1)
            return 1;
        if (b == 1)
            return 0; 
        int m_size = 32;
        vector<long long> m_dict(m_size, 1); 
        m_dict[1] = a % b;
        for (int i = 2; i < m_size; i++) {
            m_dict[i] = m_dict[i - 1] * m_dict[i - 1] % b;
        }
        int shift = 0;
        long long m_res = 1;
        while (shift <= 31) {
            if (1 << shift & n) {
                m_res *= m_dict[shift + 1];
                m_res %= b;
            }
            shift++;
        }
        return m_res;
    }
};
