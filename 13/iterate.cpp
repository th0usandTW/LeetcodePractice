class Solution {
public:
    int func(char c) {
        switch (c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        }
    }
    
    int romanToInt(string s) {
        int total = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (func(s[i]) >= func(s[i+1]))
                total += func(s[i]);
            else
                total -= func(s[i]);
        }
        
        total += func(s[s.size()-1]);
        return total;
    }
};
