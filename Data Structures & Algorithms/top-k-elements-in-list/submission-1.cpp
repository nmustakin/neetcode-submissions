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
        int least_k_count = 0; 
        int k_list[k]; 
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++; 
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        for(auto& entry: count){
            min_heap.push({entry.second, entry.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        vector<int> results;
        for(int i=0; i<k;i++){
            results.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return results; 
    }
};
