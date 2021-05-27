class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        if (intervals.size() == 0)
            return ans;
        if (intervals.size() == 1)
            return intervals;
        
        // Sort it to make start in ascending order
        for (int i = 0; i < intervals.size(); i++) {
            int smaller = i;
            for (int j = i+1; j < intervals.size(); j++) {
                if (intervals[smaller][0] > intervals[j][0]) {
                    smaller = j;
                }
            }
            if (smaller != i) {
                auto tmp = intervals[i];
                intervals[i] = intervals[smaller];
                intervals[smaller] = tmp;
            }
        }
        //sort(intervals.begin(), intervals.end());
        
        vector<int> tmp(2);
        for (int i = 0; i < intervals.size(); i++) {
            tmp = intervals[i];
            
            while ((i < intervals.size()-1) && tmp[1] >= intervals[i+1][0]) {
                tmp[1] = max(tmp[1], intervals[i+1][1]);
                i++;
            }
            
            ans.push_back(tmp);
        }
        return ans;
    }
};
