class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return maxGain(nums, 0); 
    }

private:
    int maxGain(vector<int>& nums, int k){
        if(k >= nums.size()) return 0; 
        else{
            if(memo[k] != -1) return memo[k];
            memo[k] = max(maxGain(nums, k+1), nums[k] + maxGain(nums, k+2)); 
            return memo[k]; 
        }
    }
};
