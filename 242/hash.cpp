class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int, int> times;
        
        if (s.size() != t.size())
            return false;
        
        int len = s.size();
        
        for (int i = 0; i < len; i++) {
            if (times.find(s[i]) == times.end()) {
                times[s[i]] = 1;
            } else {
                times[s[i]]++;
            }
        }
        
        for (int i = 0; i < len; i++) {
            if (times[t[i]] == 0)
                return false;
            else {
                times[t[i]]--;
            }
        }
        
        return true;
    }
};
