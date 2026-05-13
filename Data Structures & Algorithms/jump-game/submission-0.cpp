class Solution {
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> memo;
        return dfs(nums, 0, memo); 
    }

private: 
    bool dfs(vector<int>& nums, int idx, unordered_map<int,bool>& memo){
        if(memo.count(idx)) return memo[idx]; 
        if(idx == nums.size()-1) return true;
        if(!nums[idx]) return false; 
        int end = min((int)nums.size()-1, idx + nums[idx]);
        
        for(int i = idx + 1; i <= end; i++){
            if(dfs(nums, i, memo)) {
                memo[idx] = true; 
                return true; 
            }
        }

        memo[idx] = false; 
        return false;
    }
};
