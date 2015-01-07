class Solution {
public: 
    int maxProfit(vector<int> &prices) { 
        if (prices.size() < 2)
            return 0;
        vector<int> profits(prices.size(), 0);
        int minBase = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int temp_profit = prices【i】 - minBase;
            profits【i】 = max(temp_profit, profits[i - 1]);
            if (minBase > prices【i】)
                minBase = prices【i】;
        }
        int maxPrice = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            int temp_profit = maxPrice - prices【i】;
            profits【i】 += temp_profit > 0 ? temp_profit : 0;
            if (maxPrice < prices【i】)
                maxPrice = prices【i】;
        }
       return *max_element(profits.begin(), profits.end());
    }
};