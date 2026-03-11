
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // variable to track the maximum profit found so far
        int maxProfit = 0;

        // outer loop represents the buying day
        for (int i = 0; i < prices.size(); i++) {
            // inner loop represents the selling day
            // selling must happen after buying → start from i+1
            for (int j = i + 1; j < prices.size(); j++) {
                // calculate profit if we buy on day i and sell on day j
                int profit = prices[j] - prices[i];

                // update maximum profit if current profit is larger
                maxProfit = max(maxProfit, profit);
            }
        }

        // if no profit exists maxProfit remains 0
        return maxProfit;
    }

    int buyAndSell(vector<int>& prices) {
        // maximum profit we can achieve
        int maxProfit = 0;

        // minimum price seen so far while traversing the array
        int minPrice = INT_MAX;

        // traverse each day
        for (int i = 0; i < prices.size(); i++) {
            // if current price is smaller than previous minimum
            // update minimum price (best day to buy so far)
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            else {
                // calculate profit if selling today
                int profit = prices[i] - minPrice;

                // update maximum profit if this transaction is better
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit : " << sol.maxProfit(prices) << endl;
    cout << "Max Profit : " << sol.buyAndSell(prices) << endl;
    return 0;
}
