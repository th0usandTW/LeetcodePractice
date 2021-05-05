class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, median = nums.size()/2;
        map<int, int> counter;
        
        for (int i = 0; i < nums.size(); i++)
        {
            counter[nums[i]]++;
            if (counter[nums[i]] > median)
                return nums[i];
        }
        return 0;
    }
};
