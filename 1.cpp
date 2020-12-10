class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hm;
        int numberToFind;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++)
        {
            numberToFind = target - nums[i];
            if (hm.find(numberToFind) != hm.end())
            {
                ans.push_back(i);
                ans.push_back(hm[numberToFind]);
                return ans;
            }
            hm[nums[i]] = i;
        }
        
        return ans;
    }
};
