class Solution {
public:
    int bs(vector<int>& nums, int target, int left, int right) {
        int mid = (right-left)/2;
                
        if(target <= nums[left])
            return left;
        if(target == nums[right])
            return right;
        if(target > nums[right])
            return right+1;
        
        if(target == nums[mid])
            return mid;
        else if (target > nums[mid])
            return bs(nums, target, mid+1, right-1);
        else
            return bs(nums, target, left+1, mid-1);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size()-1);
    }
};
