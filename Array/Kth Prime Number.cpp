class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        vector<long long> m_candidates(k + 1, 1); 
        int three_index = 0;
        int five_index = 0;
        int seven_index = 0;
        int i = 1;
        while (i <= k) {
            long long cur_prime = min(min(m_candidates[three_index] * 3, m_candidates[five_index] * 5), 
                m_candidates[seven_index] * 7);
            m_candidates[i] = cur_prime;
            if (m_candidates[three_index] * 3 == cur_prime) {
                three_index++;
            }
            if (m_candidates[five_index] * 5 == cur_prime) {
                five_index++;
            }
            if (m_candidates[seven_index] * 7 == cur_prime) {
                seven_index++;
            }
            i++;
        }
        return m_candidates[k];
    }
};
