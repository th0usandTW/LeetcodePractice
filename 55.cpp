class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minStep(nums.size(), INT_MAX);
        
        minStep[0] = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            // We cannot move forward if step = 0, so we mark it as MAX to avoid get here
            if (nums[i] == 0)
                minStep[i] = INT_MAX;
            
            int numOfSetps = nums[i];
            int j = i+1;
            // Update the min step in range of numOfSetps
            while ((numOfSetps > 0) && (j < nums.size()))
            {
                if (minStep[i] + 1 < minStep[j])    // Update the min steps if we can get here from nums[i]
                    minStep[j] = minStep[i]+1;
                j++;
                numOfSetps--;
            }
            
        }
        return minStep[nums.size()-1];
    }
};
