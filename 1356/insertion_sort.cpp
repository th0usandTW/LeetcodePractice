class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> v;
        
        for (int i = 0; i < arr.size(); i++) {
            int tmp = arr[i];
            int count = 0;
            while (tmp > 0) {
                count += tmp % 2;
                tmp >>= 1;
            }
            v.push_back(count);
        }
        
        for (int i = 1; i < arr.size(); i++) {
            int tmp = v[i], tmp2 = arr[i];
            int j = i-1;
            while (j >= 0) {
                if (v[j] > tmp || (v[j] == tmp) && arr[j] > tmp2) {
                    v[j+1] = v[j];
                    arr[j+1] = arr[j];
                } else 
                    break;
                j--;
            }
            v[j+1] = tmp;
            arr[j+1] = tmp2;
        }
        
        
        return arr;
    }
};
