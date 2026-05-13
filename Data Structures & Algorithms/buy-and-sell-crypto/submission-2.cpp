class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int maxP = 0; 

        for(int sellP : prices){
            maxP = max(maxP, sellP - minBuy); 
            minBuy = min(minBuy, sellP);
        }
        return maxP; 
    }
};
