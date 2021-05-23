class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> map;
        vector<string> ans;
        string str;
        
        if (s.length() < 10)
            return ans;
        
        for (int i = 0; i <= s.length() - 10; i++) {
            str = s.substr(i, 10);
            map[str]++;
            if (map.find(str) != map.end()) {
                if (map[str] == 2)
                    ans.push_back(str);
            }
        }

        
        return ans;
    }
};
