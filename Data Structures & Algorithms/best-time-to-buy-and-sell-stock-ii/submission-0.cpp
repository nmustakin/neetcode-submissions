class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        return rec(prices, 0, false, dp);
    }

private:
    int rec(vector<int>& prices, int idx, int holding, vector<vector<int>>& dp){
        if(dp[idx][holding] != -1) return dp[idx][holding];
        if(holding){
            if(idx == prices.size()-1) return prices[idx]; 
            int res = max(rec(prices, idx+1, 0, dp) + prices[idx],
                    rec(prices, idx+1, 1, dp));
            dp[idx][holding] = res; 
            return res; 
        }
        else{
            if(idx == prices.size()-1) return 0; 
            int res = max(rec(prices, idx+1, 1, dp) - prices[idx],
                    rec(prices, idx+1, 0, dp));
            dp[idx][holding] = res; 
            return res; 
        }
    }
};