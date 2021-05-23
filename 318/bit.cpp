class Solution {
public:
    int maxProduct(vector<string>& words) {
        int max_len = 0;
        vector<int> flag;
        int size = words.size();
        
        for (int i = 0; i < size; i++) {
            int tmp = 0;
            for (int j = 0; j < words[i].length(); j++) {   // Use flag to record letter
                int offset = words[i][j] - 'a';
                tmp |= (1 << offset);
            }
            flag.push_back(tmp);
        }
        
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if ((flag[i] & flag[j]) == 0) {       // There is no letters shared by word[i] and word[j]
                    int len = words[i].length() * words[j].length();
                    max_len = max(max_len, len);
                }
            }
        }
        
        return max_len;
    }
};
