class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int first = -1, last = -1;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            if (nums[left] == target) {
                first = left;
            }
            if (nums[right] == target) {
                last = right;
            }
            
            if ((first != -1) && (last != -1))
                break;
            
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                // nums[mid] = target
                // If left bound we haven't, then set left = left + 1;
                // If right bound we haven't, then set right = right - 1;
                if (first == -1)
                    left = left + 1;
                if (last == -1)
                    right = right - 1;
            }
        }
        return {first, last};
    }
};
