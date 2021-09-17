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

int top_down(string s1, string s2){
    vector<vector<int>> dp(s1.size() +1);
    dp[0].assign(s2.size() +1, 0);
    for(int i=1; i<=s1.size(); i++){
        dp[i].assign(s2.size() +1, -1);
        dp[i][0] = 0;
    }
    int max_val = 0;
    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
            max_val = max(max_val, dp[i][j]);
        }
    }

    display(dp);
    return max_val;
}

int main(){
    string s1 = "abcdaf", s2 = "abcbcf";
    cout<<top_down(s1,s2)<<endl;

    return 0;
}