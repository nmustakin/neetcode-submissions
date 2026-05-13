class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>>res; 
        for(int i=0 ; i<nums.size()-2; i++){
            if(i !=0 && nums[i-1] == nums[i]) continue; 
            int left = i + 1;
            int right = nums.size() - 1; 
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0) right--;
                else if(sum < 0) left++; 
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; 
                    while(nums[left] == nums[left-1]) left++; 
                }
            }
        } 

        return res; 
    }

};
