class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<string, int> map;
        int max_len = 0;
        
        // Sort by length (insertion sort)
        for (int i = 1; i < words.size(); i++) {
            int j;
            string tmp = words[i];
            for (j = i-1; j >= 0 && words[j].length() > tmp.length(); j--) {
                words[j+1] = words[j];
            }
            words[j+1] = tmp;
        }    
        
        for (int i = 0; i < words.size(); i++) {
            map[words[i]] = 1;  // Set map[] to 1 to assume it has no predecessor
            // Remove char one by one to check if we can found any predecessor
            for (int j = 0; j < words[i].size(); j++) {
                string s = words[i];
                s.erase(j, 1);
                if (map.find(s) != map.end()) {
                    // If we found a predecessor, then compare it(max_len of predecessor) with the max_len
                    map[words[i]] = max(map[s] + 1, map[words[i]]);
                }             
            }
            max_len = max(max_len, map[words[i]]);
        }
        
        return max_len;
    }
};
