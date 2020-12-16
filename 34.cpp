class Solution {
public:
    int startIdx = INT_MAX, endIdx = INT_MIN;
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        if (nums.size() == 0)
            return {-1, -1};
        
        
        while (left <= right)
        {
            if (nums[left] == target)
                updateIdx(left);
            if (nums[right] == target)
                updateIdx(right);
            
            int mid = (left + right)/2;
            if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
            else
            {
                updateIdx(mid);
                left += 1;
                right -= 1;
            }
        }
        
        // Did not find any target
        if (startIdx == INT_MAX || endIdx == INT_MIN)
            return {-1, -1};
        
        return {startIdx, endIdx};
    }
private:
    void updateIdx(int index) {
        if (index < startIdx)
            startIdx = index;
        if (index > endIdx)
            endIdx = index;
    }
};
