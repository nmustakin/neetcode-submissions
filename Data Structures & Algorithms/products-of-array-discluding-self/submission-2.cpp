class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size());
        vector<int> output; 

        for(int i = 0, running = 1; i< nums.size(); i++){
            prefix.push_back(running);
            running *= nums[i];
        }
        for(int i=nums.size() - 1, running=1; i >= 0; i--){
            suffix[i] = running;
            running *= nums[i]; 
        }

        for(int i = 0; i<nums.size(); i++){
            cout << prefix[i] << "\t" << suffix[i] << endl;
            output.push_back(prefix[i] * suffix[i]);
        }
        return output; 
    }
};
