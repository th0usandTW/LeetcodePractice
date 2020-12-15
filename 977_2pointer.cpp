class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());   
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int count = 0;
        
        while (left <= right)
        {
            if (abs(nums[left]) <= abs(nums[right]))
            {
                ans[len - count - 1] = pow(nums[right--], 2);
            }
            else
            {
                ans[len - count - 1] = pow(nums[left++], 2);
            }
            count++;
        }
        
        return ans;
    }
};
