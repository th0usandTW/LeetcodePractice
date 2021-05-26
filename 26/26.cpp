class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        if (nums.size() == 0)
            return 0;
        
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] != nums[i+1]) {
                nums[count+1] = nums[i+1];
                    count++;
            }
        }
        return count + 1;
    }
};
