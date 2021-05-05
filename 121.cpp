class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minPrice;
        int MaxProfit = 0, profit;
        
        minPrice.push_back(prices[0]);
        for (int i = 1; i < prices.size(); i++)
        {
            // Only calculate profit when it > 0
            if (prices[i] > minPrice[i-1])
            {
                profit = prices[i] - minPrice[i-1];
                if (profit > MaxProfit)
                    MaxProfit = profit;
                
                // Update min price
                minPrice.push_back(minPrice[i-1]);
            }
            else
                minPrice.push_back(prices[i]);  // Update min price
        }
        
        return MaxProfit;
    }
};
