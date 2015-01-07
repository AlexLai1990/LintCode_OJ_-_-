class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int m_res = 0;
        if (prices.size() < 2)
            return m_res;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                m_res += prices[i] - prices[i - 1];
        }
        return m_res;
    }
};
