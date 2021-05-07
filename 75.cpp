class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numOfZero = 0, numOfOne = 0;
        int endOfZero, endOfOne;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                numOfZero++;
            else if (nums[i] == 1)
                numOfOne++;    
        }
        endOfZero = numOfZero;
        endOfOne = numOfZero + numOfOne;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < endOfZero)
                nums[i] = 0;
            else if (i < endOfOne)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};
