#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void display(vector<vector<int>> v){
    for(int i=0; i<v.size(); i++){
        display(v[i]);
    }
}

int recurImp(string s1, string s2, int m, int n){
    if(m==0 || n==0){
        return 0;
    }
    if(s1[m-1]==s2[n-1]){
        return 1 + recurImp(s1,s2, m-1, n-1);
    }
    else{
        return max(recurImp(s1, s2, m-1, n), recurImp(s1, s2, m, n-1));
    }
}

int memoization_dp(string s1, string s2, int m, int n, vector<vector<int>> &dp){
    if(m==0 || n==0){
        dp[m][n] = 0;
        return 0;
    }
    if(dp[m][n] == -1)
    {
        if(s1[m-1]==s2[n-1]){
            dp[m][n] = 1 + memoization_dp(s1,s2, m-1, n-1, dp);
        }
        else{
            dp[m][n] = max(memoization_dp(s1, s2, m-1, n, dp), memoization_dp(s1, s2, m, n-1, dp));
        }
    }
    // else{
    //     cout<<"Time saved"<<endl;
    // }
    return dp[m][n];
}

int dynamicApproach(string s1,string s2){
    vector<vector<int>> td_dp(s1.size()+1);

    // Initialization
    td_dp[0].assign(s2.size()+1, 0);

    for(int i=1; i<=s1.size(); i++){
        td_dp[i].assign(s2.size()+1, -1);
        td_dp[i][0] = 0;
    }
    
    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){
            if(s1[i-1] == s2[j-1]){
                td_dp[i][j] = 1 + td_dp[i-1][j-1];
            }
            else{
                td_dp[i][j] = max(td_dp[i-1][j], td_dp[i][j-1]);
            }
        }
    }
    display(td_dp);
    int i=s1.size(), j=s2.size();
    string res = "";
    while(i!=0 || j!=0){
        if(s1[i-1] == s2[j-1]){
            res+=s1[i-1];
            i--;
            j--;
        }
        else{
            if(td_dp[i-1][j] > td_dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<res<<endl;

    return td_dp.back().back();
}

int main(){
    string s1 = "abcdaf", s2 = "acbcf";
    cout<<recurImp(s1,s2,s1.size(), s2.size())<<endl;

    vector<vector<int>> dp(s1.size()+1);
    for(int i=0; i<=s1.size(); i++){
        dp[i].assign(s2.size()+1, -1);
    }

    cout<<memoization_dp(s1,s2,s1.size(), s2.size(), dp)<<endl;
    // display(dp);

    cout<<dynamicApproach(s1,s2);
    return 0;
}