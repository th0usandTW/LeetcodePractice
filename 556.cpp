class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digit(10);
        long ans = 0;
        int origVal = n;
        int i = 0;

        while (n > 0)
        {
            digit[i] = n % 10;
            n /= 10;
            i++;
        }
        
        int highDigitIdx = 1;
        
        while (highDigitIdx < i)
        {
            int lowDigitIdx = highDigitIdx - 1;
            for (int k = 0; k <= lowDigitIdx; k++)
            {
                // Try to find lower digit > higher digit
                if (digit[k] > digit[highDigitIdx])
                {
                    // Swap digits
                    int tmp = digit[k];
                    digit[k] = digit[highDigitIdx];
                    digit[highDigitIdx] = tmp;
                    
                    // sort the digits from range 0 ~ lowDigitIdx
                    for (int j = 0; j <= lowDigitIdx-1; j++)
                    {
                        for (int z = j + 1; z <= lowDigitIdx; z++)
                        {
                            if (digit[z] > digit[j])
                            {
                                tmp = digit[j];
                                digit[j] = digit[z];
                                digit[z] = tmp;
                            }
                        }
                    }
                    
                    // assemble the digits
                    for (int j = i-1; j >= 0; j--)
                    {
                        ans *= 10;
                        ans += digit[j];
                    }
                    if (ans < INT_MAX)
                        return ans;
                    else
                        return -1;
                }
            }
            highDigitIdx++;
        }
        return -1; 
    }
};
