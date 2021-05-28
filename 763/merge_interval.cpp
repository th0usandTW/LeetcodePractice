class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int,int>> map;
        vector<vector<int>> pos;
        vector<int> ans;

        // Record the start and end position of each letter
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) == map.end()) {
                map[s[i]].first = i;
                map[s[i]].second = i;
            } else {
                map[s[i]].second = i;
            }
        }
        
        vector<int> tmp(2);
        for (auto it = map.begin(); it != map.end(); it++) {
            tmp[0] = it->second.first;
            tmp[1] = it->second.second;
            pos.push_back(tmp);
        }
        
        // Sort by start pos
        sort(pos.begin(), pos.end());
        
        int start, end;
        for (int i = 0; i < pos.size(); i++) {
            start = pos[i][0];
            end = pos[i][1];
            while ((i < pos.size()-1) && end >= pos[i+1][0]) {
                end = max(end, pos[i+1][1]);
                i++;
            }
            
            ans.push_back(end-start+1);
        }
        
        return ans;
    }
};
