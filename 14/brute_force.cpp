class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int i = 0; i < strs[0].size(); i++) {
            int j;
            for (j = 0; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i])
                    return prefix;
            }
            if (j == strs.size())
                prefix += strs[0][i];
        }
        
        return prefix;
    }
};
