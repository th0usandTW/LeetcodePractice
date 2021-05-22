class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> stk;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                int idx = stk.top();
                stk.pop();
                ans[idx] = nums[i];
            }
            stk.push(i);
        }
        
        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            
            int count = nums.size();
            int next = idx;
            while (count > 0) {
                next = (next+1) % nums.size();
                if (nums[next] > nums[idx]) {
                    ans[idx] = nums[next];
                    break;
                }
                count--;
            }
        }
        
        return ans;
    }
};
