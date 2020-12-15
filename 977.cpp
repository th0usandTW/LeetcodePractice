class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int smallestIdx = 0;
        vector<int> ans;
            
        for (int i = 1; i < nums.size(); i++)
        {
            if (abs(nums[i]) < abs(nums[smallestIdx]))
                smallestIdx = i;
        }
        ans.push_back(pow(nums[smallestIdx], 2));
        
        int left  = smallestIdx - 1;
        int right = smallestIdx + 1;
        while ((left >=0) || (right <= nums.size()-1))
        {
            // Compare which one is smaller
            if ((left >=0) && (right <= nums.size()-1))
            {
                if (abs(nums[left]) <= abs(nums[right]))
                {
                    ans.push_back(pow(nums[left--], 2));
                }
                else
                {
                    ans.push_back(pow(nums[right++], 2));
                }
            }
            else if (left >=0)
            {
                ans.push_back(pow(nums[left--], 2));
            }
            else
            {
                ans.push_back(pow(nums[right++], 2));
            }
        }
        
        return ans;
    }
};
