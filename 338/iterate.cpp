class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        
        for (int i = 0; i <= num; i++) {
            int cnt = 0;
            int tmp = i;
            while (tmp > 0) {
                cnt += tmp % 2;
                tmp /= 2;
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
