class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        int ans = 0;
        
        // Store sum of bit X in to bits vector
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            for (int j = 0; j < 32; j++) {
                bits[j] += n & 1;
                n >>= 1;
                if (n == 0)
                    break;
            }
        }
        
        for (int i = 31; i >= 0; i--) {
            int n = bits[i] % 3;        // remove bits from number appear 3 times
            ans += n << i;
        }
        
        return ans;
    }
};
