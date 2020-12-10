class Solution {
public:
    int maxArea(vector<int>& height) {
        int w, h, area, max = 0;
        int left = 0, right = height.size()-1;
        
        while (left < right)
        {
            w = right - left;
            if (height[left] <= height[right])
            {
                h = height[left];
                left++;
            } 
            else 
            {
                h = height[right];
                right--;
            }

            area = h * w;
            
            if (area > max)
                max = area;
        }
        
        return max;
    }
};
