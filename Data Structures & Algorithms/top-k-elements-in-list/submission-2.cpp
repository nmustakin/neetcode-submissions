class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //logic : 
        //start counting frequency of elements
        //keep count in a hashmap
        //keep a list of pointers of size k
        //issue, sorting hashmap
        //keep another

        unordered_map<int, int> count; 
        
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++; 
        }
        vector<vector<int>> freq(nums.size() + 1); 

        for(const auto& entry: count){
            freq[entry.second].push_back(entry.first);
        }
        
        vector<int> results;
        for(int i = freq.size() -1; i> 0; i--){
            for(int n: freq[i]){
                results.push_back(n);
                if(results.size() == k) return results; 
            }
        }
        
        return results; 
    }
};
