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
        vector<pair<int,int>> elements(count.begin(), count.end());
        sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            }); 
        vector<int> results; 
        for(int i =0; i<k ; i++){
            results.push_back(elements[i].first); 
        }
        return results; 
    }
};
