class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists(nums.begin(), nums.end());

        int longest = 0; 

        for(int num : exists){
            if(exists.find(num-1) == exists.end()){
                //that means this is the start of the sequence
                int len = 1;
                int curr = num+1; 
                while(exists.find(curr) != exists.end()){
                    len++;
                    curr++; 
                }
                longest = max(longest, len); 
            }
        }
        return longest; 
    }
};
