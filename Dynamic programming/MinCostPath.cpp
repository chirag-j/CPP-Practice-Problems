// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right, 
// which minimizes the sum of all numbers along its path.

vector<vector<int>> dp;
class Solution {
public:
    int pathRecur(vector<vector<int>>& grid, int x, int y){
        if(x>=grid.size() || y>=grid[0].size()){return 1e7;}
        if(x+1==grid.size() && y+1==grid[0].size()){return grid[x][y];}
        
        if(dp[x][y]!=-1){return dp[x][y];}
        
        dp[x][y] = min(pathRecur(grid,x+1,y),pathRecur(grid,x,y+1)) +grid[x][y];
        return dp[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.clear();
        dp.assign(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        return pathRecur(grid,0,0);
    }
};