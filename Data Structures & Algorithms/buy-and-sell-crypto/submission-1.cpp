class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0; 
        int buy_idx = 0;
        int sell_idx = 1; 
        int max_profit = prices[sell_idx] - prices[buy_idx]; 
        while(buy_idx < prices.size()){
            if(sell_idx == prices.size()){
                buy_idx++; 
                sell_idx = buy_idx; 
            }
            int profit = prices[sell_idx] - prices[buy_idx];
            if(profit < 0){
                buy_idx++; 
                sell_idx = buy_idx;
            }
            if(profit > max_profit) max_profit = profit;
            sell_idx++; 
            
        }

        return (max_profit < 0)? 0: max_profit; 
    }
};
