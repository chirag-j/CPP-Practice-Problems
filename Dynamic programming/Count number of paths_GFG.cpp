class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>> dp(a);
        for(int i=0; i<a; i++){
            dp[i].resize(b);
            if(i!=0){
                dp[i][0] = 1;
            }
        }
        for(int i=1; i<b; i++){
            dp[0][i] = 1;
        }
        dp[0][0] = 1;
        for(int i=1; i<a; i++){
            for(int j=1; j<b; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp.back().back();
        
    }
};