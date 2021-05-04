class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] > nums[i])
            {
                // We only can increase nums[i-1] because nums[i-2] > nums[i], decrease num[i-1] will let num[i-2] > num[i-1]
                if ((i-2 >= 0) && nums[i-2] > nums[i])
                    nums[i] = nums[i-1];
                else
                    nums[i-1] = nums[i];    // We can decrease nums[i-1] becasue nums[i-2] <= nums[i]
                count++;
            }
            
            if (count > 1)
                return false;
        }

        return true;
    }
};
