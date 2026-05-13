class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int fullProduct = 1;
        set<int> zeroIdx; 
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0) fullProduct *= nums[i];
            else{
                zeroIdx.insert(i); 
            }
        }
        vector<int> output;
        for(int i=0; i<nums.size();i++){
            if(zeroIdx.empty()){
                output.push_back((int)fullProduct / (int)nums[i]);
            }
            else{
                if(zeroIdx.find(i) != zeroIdx.end()){
                    if(zeroIdx.size() > 1) output.push_back(0);
                    else output.push_back(fullProduct);
                }
                else{
                    output.push_back(0);
                }
            }
        }

        return output; 
    }
};
