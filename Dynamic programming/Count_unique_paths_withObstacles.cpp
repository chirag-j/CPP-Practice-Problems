// The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid

// An obstacle and space is marked as 1 and 0 respectively in the grid.


// Key -- during initialization, there will be value of 1 till we encounter and obstacle,
// afer that the value will be zero (for first row and 1st column of dp)
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int> (n));
    
    dp[0][0] = !obstacleGrid[0][0];
    for(int j=1; j<n; j++){
        dp[0][j] = dp[0][j-1] && (!obstacleGrid[0][j]);
    }
    for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] && (!obstacleGrid[i][0]);
    }
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = (obstacleGrid[i][j])? 0:dp[i-1][j] + dp[i][j-1];
        }
    } 
    return dp[m-1][n-1];
}