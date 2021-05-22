class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> stk;     // stack for index
        int len = nums.size();
        
        for (int i = 0; i < len*2; i++) {
            int cur_num = nums[i % len];
            while (!stk.empty() && cur_num > nums[stk.top()]) {
                ans[stk.top()] = cur_num;
                stk.pop();
            }
            // Only push real idx
            if (i < len)
                stk.push(i);
        }
        
        return ans;
    }
};
