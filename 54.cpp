class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        int nums = rowLen * colLen;
        int row = 0, col = 0, count = 0;
        vector<vector<bool>> visited(rowLen, vector<bool>(colLen));
        
        while (count < nums)
        {
            // move right
            while (col < colLen && !visited[row][col])
            {
                ans.push_back(matrix[row][col]);
                visited[row][col] = true;
                col++;
                count++;
            }
            col--;
            row++;
            
            // move down
            while (row < rowLen && !visited[row][col])
            {
                ans.push_back(matrix[row][col]);
                visited[row][col] = true;
                row++;
                count++;
            }
            row--;
            col--;
            
            // move left
            while(col >= 0 && !visited[row][col])
            {
                ans.push_back(matrix[row][col]);
                visited[row][col] = true;
                col--;
                count++;
            }
            col++;
            row--;
            
            // move up
            while (row >= 0  && !visited[row][col])
            {
                ans.push_back(matrix[row][col]);
                visited[row][col] = true;
                row--;
                count++;
            }
            row++;
            col++;
        }
        return ans;
    }
};
