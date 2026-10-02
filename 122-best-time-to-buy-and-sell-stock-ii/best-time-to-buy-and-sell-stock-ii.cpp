class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            given an array prices where price[i] is the price of a given stock on the ith day 

            - on each day, you may decide to by and/or sell the stock 
            - you can only hold at most one share of the stock at any time 
            - you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock 

            return the max profit you can achieve 

            total_profit = 0
            buy = 7
            profit = 0

            prices = [7,1,5,3,6,4]
                        i          profit = max(0, 1 - 7) = 0
                          i        profit = max(0, 5-1) = 4
                            i      profit = max(0, 3-5) = 0
                              i    profit = max(0, 6-3) = 3
                                i  profit = max(0, 4-6) = 0

                                total = 7  

            prices = [1,2,3,4,5]
                        i       profit = max(0, )                  

        */

        int profit {};

        for (int i {1}; i < prices.size(); i++){
            profit += std::max(0, prices[i] - prices[i-1]);
        }

        return profit;

    }
};