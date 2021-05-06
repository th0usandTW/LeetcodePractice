class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, left = 0, right = 0;
        
        if (nums.size() == 1)
            return 0;
        
        while (left <= right)
        {
            int farthest = right;
            for (int i = left; i <= right; i++)
            {
                // Find farthest item we can get so that we can find min steps
                farthest = max(farthest, i + nums[i]);
                if (farthest >= nums.size()-1)
                    return step+1;
            }
            
            step++;
            left = right + 1;
            right = farthest;
        }
        
        return -1;
    }
};
