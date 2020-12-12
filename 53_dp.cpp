class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        vector<int> maxTable;
        
        maxTable.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            if (maxTable[i-1] + nums[i] > nums[i])
                maxTable.push_back(maxTable[i-1] + nums[i]);
            else
                maxTable.push_back(nums[i]);
            
            // Update max
            if (maxTable[i] > max)
                max = maxTable[i];
        }
        
        return max;
    }
};
