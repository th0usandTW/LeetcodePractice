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
            bin = to_string(sum%2) + bin; // put the current bin at the end so we don't need to reverse it.
            
            i--;
            j--;
        }
        
        return bin;
    }
};
