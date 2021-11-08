// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
// Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.


// Note the wall thickness are assumed 0;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, n = height.size();
        int j = n, i=1;
        while(i<=n && j>i){
            res = max(res,min(height[i-1],height[j-1])*(j-i));
            
            if(height[i-1]>height[j-1]){j--;}
            else{i++;}
        }
        return res;
    }
};