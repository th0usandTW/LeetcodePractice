class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i, top;
        
        if (arr.size() < 3)
            return false;
        
        // Find top first
        for (i = 1; i < arr.size()-1; i++)
        {
            if ((arr[i-1] < arr[i]) && (arr[i] > arr[i+1]))
            {
                top = i;
                break;
            }
        }
        
        // Cannot find top
        if (i == arr.size()-1)
            return false;
        
        // Return false if arr[i-1] >= arr[i]
        int left = top;
        while (left > 0)
        {
            if (arr[left-1] >= arr[left])
                return false;
            left--;
        }
        
        // Return false if arr[i] <= arr[i+1]
        int right = top;
        while (right < arr.size()-1)
        {
            if (arr[right] <= arr[right+1])
                return false;
            right++;
        }
        
        return true;
    }
};
