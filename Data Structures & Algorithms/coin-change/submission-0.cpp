class Solution {
public:
    unordered_map<int, int> memo; 
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, amount); 
        if (res == 1e9) return -1; 
        else return res; 
    }

    int dfs(vector<int>& coins, int left){
        if(!left) return 0;
        if(memo.count(left)) return memo[left];
        int res = 1e9; 

        for(int coin: coins){
            if(left - coin >= 0){
                res = min(res, 1 + dfs(coins, left-coin));
            }
        }

        memo[left] = res; 
        return res; 
    }
};
