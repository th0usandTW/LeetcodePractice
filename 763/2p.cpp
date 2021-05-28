class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPostion(26);
        vector<int> ans;
        int len = s.size();
        
        for (int i = 0; i < len; i++) {
            lastPostion[s[i] - 'a'] = i;
        }
        
        int start = 0;
        while (start < len) {
            int end = lastPostion[s[start] - 'a'];
            int j = start;
            while (j != end) {
                end = max(end, lastPostion[s[j] - 'a']);
                j++;
            }
            
            ans.push_back(end - start + 1);
            start = end + 1;
        }
        
        return ans;
    }
};
