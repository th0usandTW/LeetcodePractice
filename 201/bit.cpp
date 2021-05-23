class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        vector<int> msb;
        int ans = 0;
        int i = 0;
        
        if (left == 0 && right == 0)
            return 0;
        
        while (left || right) {
            int bit_left = left & 1;
            int bit_right = right & 1;
            
            if (bit_left == bit_right) {
                if (bit_left == 1)
                    msb.push_back(i);
            } else
                msb.clear();
            
            left >>= 1;
            right >>= 1;
            i++;
        }
        
        for (int i = 0; i < msb.size(); i++)
            ans += (1 << msb[i]);
        
        return ans;
    }
};
