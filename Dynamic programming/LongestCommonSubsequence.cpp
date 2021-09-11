#include<iostream>
#include<vector>
#include<string>

using namespace std;

// void recursiveImplementation()

int dynamicApproach(string s1,string s2){
    vector<vector<int>> dp(s1.size()+1);

    // Initialization
    for(int i=0; i<=s1.size(); i++){
        dp[i].resize(s2.size());
        dp[i][0] = 0;
        if(i == 0){
            for(int j=1; j<=s2.size(); j++){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=1; i<=s2.size(); i++){
        for(int j=1; j<=s1.size(); j++){
            if(s1[j-1] == s2[i-1]){
                // Watch yt and come back
            }
        }
    }

}

int main(){
    
    return 0;
}