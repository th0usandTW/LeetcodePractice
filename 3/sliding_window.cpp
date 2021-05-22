class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0, tail = 0;
        map<char, int> map;
        int max_len = 0;
        int len = 0;
        
        while (tail < s.length()) {
            if (map.find(s[tail]) == map.end()) {   // s[tail] does not in current string
                map[s[tail]] = 1;
                tail++;
                len++;
                max_len = max(max_len, len);
            } else {
                while (head < tail && s[head] != s[tail]) {
                    map.erase(s[head]);
                    head++;
                    len--;
                }
                map.erase(s[head++]);
                len--;
            }
        }
        
        return max_len;
    }
};
