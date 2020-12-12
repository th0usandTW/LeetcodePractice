class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int>(n));
        int i, j;
        
        // First row only has one posibility (i.e. get there from left)
        for (j = 0; j < n; j++)
        {
            path[0][j] = 1;
        }
        
        // First col only has one posibility (i.e. get there from up)
        for (i = 0; i < m; i++)
        {
            path[i][0] = 1;
        }
        
        // path[i][j] = path[i-1][j] + path[i][j]
        for (i = 1; i < m; i++)
        {
            for (j = 1; j < n; j++)
            {
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        
        return path[m-1][n-1];
    }
};
