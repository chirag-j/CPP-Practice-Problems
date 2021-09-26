#include<iostream>
#include<vector>
using namespace std;

bool inlimit(vector<int> pos, vector<int> dir, int n){
    if(pos[0]+dir[0]>=0 && pos[0]+dir[0] <= n-1){
        if(pos[1]+dir[1]>=0 && pos[1]+dir[1] <= n-1){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n);
        for(int i=0; i<n; i++){
            mat[i].assign(n, -1);
        }
        // bool way = true;
        int x = 1;
        vector<int> pos = {0,0}, dir = {0,1};
        mat[0][0] = 1;
        x++;
        while(true){
            cout<<pos[0]<<" "<<pos[1]<<endl;
            if(inlimit(pos, dir, n) && mat[pos[0]+dir[0]][pos[1] + dir[1]] == -1){
                pos[0]+=dir[0];
                pos[1]+=dir[1];
            }
            else if(pos[1]<n-1 && mat[pos[0]][pos[1] +1] == -1){
                pos[1]++;
                dir = {0,1};
            }
            else if(pos[0]<n-1 && mat[pos[0] +1][pos[1]] == -1){
                pos[0]++;
                dir = {1,0};
            }
            else if(pos[1]>0 && mat[pos[0]][pos[1] -1] == -1){
                pos[1]--;
                dir = {0,-1};
            }
            else if(pos[0]>0 && mat[pos[0] -1][pos[1]] == -1){
                pos[0]--;
                dir = {-1,0};
            }
            else{
                break;
            }
            mat[pos[0]][pos[1]] = x;
            x++;
        }
        return mat;
    }
};