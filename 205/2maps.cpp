class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        map<char, char> map, map2;
        
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) == map.end() && map2.find(t[i]) == map2.end()) {
                map[s[i]] = t[i];
                map2[t[i]] = s[i];
            } else {
                if (map[s[i]] != t[i] || map2[t[i]] != s[i])
                    return false;
            }
        }
        
        return true;
    }
};
