class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        
        while ((left < right) && nums[left] > nums[right]) {
            int mid = left + (right-left)/2;
            
            if (nums[mid] > nums[right]) {
                // min is at right side
                left = mid + 1;
            } else {
                // Min is at mid or left side
                // We don't set right = mid+1 to avoid the case the mid-1 is min 
                right = mid;    
            }
        }
        return nums[left];
    }
};
