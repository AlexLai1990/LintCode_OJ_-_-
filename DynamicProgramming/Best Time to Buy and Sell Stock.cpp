class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        int m_res = 0; 
        int minBase = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int temp_profit = prices[i] - minBase;
            if (temp_profit > m_res)
                m_res = temp_profit;
            if (prices[i] < minBase)
                minBase = prices[i];
        }
        return m_res;
    }
};

