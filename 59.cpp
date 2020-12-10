class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans( n, vector<int>(n) );
        int ansSize = n*n;
        
        int x = 0;
        int y = 0;
        int val = 1;
        while (val <= ansSize)
        {
            // move right
            while (y < n && (ans[x][y]==0))
            {
                ans[x][y] = val;
                val++;
                y++;
            }
            y--;
            x++;
            
            // move down
            while (x < n && (ans[x][y]==0))
            {
                ans[x][y] = val;
                val++;
                x++;
            }
            x--;
            y--;
            
            // move left
            while (y >= 0 && (ans[x][y]==0))
            {
                ans[x][y] = val;
                val++;
                y--;
            }
            y++;
            x--;
            
            // move up
            while (x >= 0 && (ans[x][y]==0))
            {
                ans[x][y] = val;
                val++;
                x--;
            }
            x++;
            y++;
        }
        
        return ans;
    }
};
