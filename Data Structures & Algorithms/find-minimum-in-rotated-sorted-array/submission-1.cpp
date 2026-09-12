class Solution {
public:
    int findMin(vector<int> &nums) {
        return nums[(helper(nums, 0, nums.size()-1))];
    }

    int helper(vector<int> &nums, int first, int last){
        if(first == last) return first;
        int middle = first + (last - first)/2;
        if(nums[middle] < nums[first]){
            return helper(nums, first+1, middle);
        }
        else if(nums[middle] > nums[last])
            return helper(nums, middle+1, last);
        
        return first;
    }
};
