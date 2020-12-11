class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] < 0)
            {
                ans = abs(nums[i]);
                break;
            }
            // Use negative value to represent the number has been visited
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        
        return ans;
    }
};
