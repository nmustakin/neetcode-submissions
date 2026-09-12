class Solution {
public:
    int findMin(vector<int> &nums) {
        int first = 0;
        int last = nums.size() - 1;

        while(first < last){
            int middle = first + (last-first)/2;
            if(nums[middle] < nums[first]){
                first = first + 1;
                last = middle; 
            }
            else if(nums[middle] > nums[last]){
                first = middle + 1;
            }
            else break;
        }

        return nums[first];
    }
};
