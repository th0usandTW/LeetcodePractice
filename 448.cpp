class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int index;
        
        for (int i = 0; i < nums.size(); i++)
        {
            index = abs(nums[i]) - 1; // array index start from 0
            if (nums[index] > 0)
                nums[index] = -nums[index]; // negate the i-th number if it still positive
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)        // We miss these numbers, so these i-th numbers are positive
                ans.push_back(i+1);
        }
        
        return ans;
    }
};
