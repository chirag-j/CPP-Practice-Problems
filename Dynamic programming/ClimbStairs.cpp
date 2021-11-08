// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. 
// In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[n] = 1;
        dp[n-1] = 1;
        
        for(int i=n-2; i>=0; i--){
            dp[i] = dp[i+1] + dp[i+2];-
        }
        return dp[0];
    }
};