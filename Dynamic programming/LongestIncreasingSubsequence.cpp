
int Solution::lis(const vector<int> &A) {
    vector<int> dp(A.size(), 1);
    int res = 1;
    for(int i=1; i<A.size(); i++){
        for(int j=0; j<i; j++){
            if(A[i]>A[j]){
                dp[i] = max(dp[i], dp[j]+1);
                res = max(res,dp[i]);
            }
        }
    }
    return res;
}