class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        
        while (left < right) {
            int mid = left + (right-left)/2;
            
            // We narrow down the array into one number, it's answer!
            // if (left == right)
            // break;
            
            // It's a sorted array, just return the left item
            if ((nums[left] < nums[mid]) && (nums[mid] < nums[right])) {
                break;
            }
            
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
