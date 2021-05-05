class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice;
        int maxProfit = 0, profit;
        
        minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > minPrice)
            {
                profit = prices[i] - minPrice;
                if (profit > maxProfit)
                    maxProfit = profit;
                
            }
            else
                minPrice = prices[i];
        }
        
        return maxProfit;
    }
};
