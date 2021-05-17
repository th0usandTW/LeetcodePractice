class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            else {
                if (stk.empty())
                    return false;
                
                char c = stk.top();
                stk.pop();
                
                if (c == '(' && s[i] != ')' ||
                    c == '{' && s[i] != '}' ||
                    c == '[' && s[i] != ']')
                    return false;
            }
        }
        
        return stk.empty();
    }
};
