class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0, tmp;
    
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                tmp = nums[i];
                nums[i] = nums[nums.size()- len -1];
                nums[nums.size()- len -1] = tmp;
                
                len++;
            }
        }
        
        return len;
    }
};
