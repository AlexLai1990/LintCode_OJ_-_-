class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        if (A.size() < 1 || m < 1)
            return 0;
        int max_value = INT_MIN;
        vector<int> m_values(m + 1, -1);
        m_values[0] = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = m; j >= A[i]; j--) {
                if (m_values[j - A[i]] != -1) {
                    int temp_value = m_values[j - A[i]] + V[i];
                    m_values[j] = max(m_values[j], temp_value);
                    max_value = max(max_value, temp_value);
                }
            }
        }
        return max_value;
    }
};
