class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int, int> mapping;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mapping[nums[i]] = 1;
        }
        
        for (int i = 1; i < nums.size()+1; i++)
        {
            if (mapping[i] == 0)
                ans.push_back(i);
        }
        
        return ans;
    }
};
