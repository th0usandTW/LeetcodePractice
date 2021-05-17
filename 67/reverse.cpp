class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        string bin = "";
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = 0;
            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum += b[j] - '0';
            
            sum += carry;
            carry = sum/2;
            bin += to_string(sum%2);
            
            i--;
            j--;
        }
        
        for (i = 0; i < bin.length()/2; i++) {
            char c = bin[i];
            bin[i] = bin[bin.length()-i-1];
            bin[bin.length()-i-1] = c; 
        }
        
        return bin;
    }
};
