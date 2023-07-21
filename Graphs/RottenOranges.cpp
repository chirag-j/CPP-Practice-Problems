// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
// If this is impossible, return -1.

class Solution {
public:
    void display(vector<int> &v){
        for(int i=0 ;i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    void display(vector<vector<int>> &v){
        for(int i=0; i<v.size(); i++){
            display(v[i]);
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> qu;
        vector<vector<int>> path(m, vector<int> (n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    path[i][j] = 0;
                    qu.push({i,j});
                }
            }
        }
        int x, y;
        while(!qu.empty()){
            x = qu.front().first;
            y = qu.front().second;
            // cout<<x<<" "<<y<<endl;
            if(x>0 && grid[x-1][y]==1){
                if(path[x-1][y] == -1 || path[x][y]+1 < path[x-1][y]){
                    path[x-1][y] = path[x][y]+1;
                    qu.push({x-1,y});
                }
            }
            if(x<m-1 && grid[x+1][y]==1){
                if(path[x+1][y] == -1 || path[x][y]+1 < path[x+1][y]){
                    path[x+1][y] = path[x][y]+1;
                    qu.push({x+1,y});
                }
            }
            if(y>0 && grid[x][y-1]==1){
                if(path[x][y-1] == -1 || path[x][y]+1 < path[x][y-1]){
                    path[x][y-1] = path[x][y]+1;
                    qu.push({x,y-1});
                }
            }
            if(y<n-1 && grid[x][y+1]==1){
                if(path[x][y+1] == -1 || path[x][y]+1 < path[x][y+1]){
                    path[x][y+1] = path[x][y]+1;
                    qu.push({x,y+1});
                }
            }
            // display(path);
            qu.pop();
        }
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && path[i][j] == -1){
                    return -1;
                }
                res = max(res, path[i][j]);
            }
        }
        return res;
        
    }
};