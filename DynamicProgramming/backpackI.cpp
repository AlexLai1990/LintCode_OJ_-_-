class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.size() < 1)
            return true;
        if (m < 1)
            return false;
        vector<int> m_backpacks(m + 1, false);
        m_backpacks[0] = true;
        for (int i = 0; i < A.size(); i++) {
            for (int j = m; j >= A[i]; j--) {
                if (m_backpacks[j - A[i]])
                    m_backpacks[j] = true;
            }
        }
        int m_res;
        for (int i = 0; i < m_backpacks.size(); i++)
            if (m_backpacks[i])
                m_res = i;
        
        return m_res;
    }
};
