class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0, curVal, tmp;
        
        if (nums.size() == 0)
            return 0;
        
        len = 1;    // at least has one number;
        curVal = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (curVal < nums[i])
            {
                curVal = nums[i]; // Update curVal 
                
                tmp = nums[len];
                nums[len] = nums[i];
                nums[i] = tmp;
                
                len++;
            }
        }
        
        return len;
    }
};
