// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
// Memory Usage: 6.5 MB, less than 70.89% of C++ online submissions for Pascal's Triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        pascal[0] = {1};
        // pascal[2] = {1,1};
        int n=1;
        while(n<numRows){
            pascal[n].assign(n+1, 1);
            for(int i=1; i<pascal[n-1].size(); i++){
                pascal[n][i] = pascal[n-1][i] + pascal[n-1][i-1];
            }
            n++;
        }
        // pascal.erase(pascal.begin());
        return pascal;
        
    }
};