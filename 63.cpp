class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();    // row
        int n = obstacleGrid[0].size(); // column
        vector<vector<int>> path(m, vector<int>(n));
        int i, j;
        
        // If start or end is blocked
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;
        
        // Only can get node [i][0] from [i-1][0], so break loop if there is obstacle
        for (i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0])
            {
                path[i][0] = -1;
                break;
            }
            else
                path[i][0] = 1;
        }
        
        // Only can get node [0][j] from [0][j-1], so break loop if there is obstacle
        for (j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j])
            {
                path[0][j] = -1;
                break;
            }
            else
                path[0][j] = 1;
        }
        
        for (i = 1; i < m; i++)
        {
            for (j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                    path[i][j] = -1;
                else
                {
                    if (path[i-1][j] > 0)
                    {
                        path[i][j] += path[i-1][j];
                    }
                    if (path[i][j-1] > 0)
                    {
                        path[i][j] += path[i][j-1];
                    }
                }
            }
        }
        
        return path[m-1][n-1];
    }
};
