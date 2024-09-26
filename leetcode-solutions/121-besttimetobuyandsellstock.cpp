##include <vector>
#include <string>
#include <algorithm> 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;  // Initialize to a large value
        int max_profit = 0;       // No profit initially
        
        // Traverse the prices array
        for (int price : prices) {
            // Update min_price if current price is lower
            if (price < min_price) {
                min_price = price;
            }
            // Calculate profit if sold at current price and update max_profit if needed
            else {
                max_profit = max(max_profit, price - min_price);
            }
        }
        
        return max_profit;
    }
};