class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        vector<int> result; 
        for(int i = 0; i<nums.size(); i++){
            cout << target - nums[i] << endl; 
            
            if(mp.find(target-nums[i]) != mp.end()){
                result.push_back(min(i, mp[target - nums[i]]));
                result.push_back(max(i,mp[target - nums[i]]));
            }
            mp[nums[i]] = i; 
        }

        return result; 
    }
};
