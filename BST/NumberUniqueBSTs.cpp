// Given an integer n, return the number of structurally unique BST's 
// which has exactly n nodes of unique values from 1 to n

// Orr-- NUmber of BSTs that can be formed with n natural numbers.
unordered_map<int,int> dp;
class Solution {
public:
    int numTrees(int n) {
        if(n==0){return 1;}
        if(n<=2){return n;}
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        int count = 0;
        for(int i=1; i<=n;i++){
            count+=(numTrees(n-i) * numTrees(i-1));
        }
        dp[n] = count;
        return count;
    }
};