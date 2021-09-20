#include<iostream>
#include<vector>

using namespace std;

template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"     ";
}

void display(vector<vector<vector<int>>> dp){
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[0].size(); j++){
            display(dp[i][j]);
        }
        cout<<endl;
    }
}

vector<vector<vector<int>>> dp;

int maxNeighbour(int i, int j, int k){
    int maxN = max(dp[i-1][j][k], dp[i][j-1][k]);
    maxN = max(maxN, dp[i][j][k-1]);
    maxN = max(maxN, dp[i][j-1][k-1]);
    maxN = max(maxN, dp[i-1][j][k-1]);
    maxN = max(maxN, dp[i-1][j-1][k]);
    return maxN;
}

int LCS(vector<int> &s1, vector<int> &s2, vector<int> s3){
    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){
            for(int k=1; k<=s3.size(); k++){
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){   //match
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] = maxNeighbour(i,j,k);
                }
            }
        }
    }
    display(dp);
    return dp.back().back().back();
}

int main(){
    // vector<int> s1 = {1,2,3}, s2 = {2,1,3}, s3 = {1,3,5};
    // vector<int> s1 = {8,3,2,1,7}, s2 = {8,2,1,3,8,10,7}, s3 = {6,8,3,1,4,7};
    vector<int> s1, s2, s3;
    int m, n, p;
    cin>>m;
    s1.resize(m);
    for(int i=0; i<m; i++){
        cin>>s1[i];
    }
    cin>>n;
    s2.resize(n);
    for(int i=0; i<n; i++){
        cin>>s2[i];
    }
    cin>>p;
    s3.resize(p);
    for(int i=0; i<p; i++){
        cin>>s3[i];
    }



    dp.resize(s1.size()+1);
    for(int i=0; i<=s1.size(); i++){
        dp[i].resize(s2.size() +1);
        dp[i][0].assign(s3.size() +1, 0);
        for(int j=1; j<=s2.size(); j++){
            if(i==0){
                dp[i][j].assign(s3.size()+1, 0);
                continue;
            }
            dp[i][j].assign(s3.size()+1, -1);
            dp[i][j][0] = 0;
        }
    }
    cout<<LCS(s1,s2,s3)<<endl;
    // display(dp);

    return 0;
}