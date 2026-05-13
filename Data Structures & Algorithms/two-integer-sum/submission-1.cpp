class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> index_map; 
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) index_map[nums[i]].push_back(i);

        for(int num: nums){
            if(index_map.find(target-num) != index_map.end()){
                vector<int> first = index_map[num];
                vector<int> second = index_map[target-num];
                if(num == target-num){
                    if(first.size()>1){
                        ans.push_back(first[0]);
                        ans.push_back(first[1]); 
                        return ans; 
                    }
                }
                else{
                    ans.push_back(first[0]);
                    ans.push_back(second[0]);
                    return ans;
                }
            }
        }

        return ans; 
    }
};
