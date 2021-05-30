class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        // We onyl have lower letter
        vector<int> count(26, 0);  
        int size = s.length();
        for (int i = 0; i < size; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0)
                return false;
        }
        
        return true;
    }
};
