// Minimum subset sum problem
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;


void display(vector<int> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void display(vector<vector<int>> v){
	for(int i = 0; i<v.size(); i++){
		display(v[i]);
	}
	cout<<endl;
}

int minSubsetSumDP(vector<int> v){
	int total = accumulate(v.begin(), v.end(), 0);
	int subsum = total/2;

	vector<vector<int>> dp;
	for(int i =0; i<=v.size(); i++){
		dp.push_back({0});
	}
	for(int i =0; i<subsum; i++){
		dp[0].push_back(0);
	}
	int temp = 0;
	for(int i=1; i<=v.size(); i++){
		for(int j=1; j<=subsum; j++){
			if(v[i-1]<=j){
				temp = max(dp[i-1][j], dp[i-1][j-v[i-1]] + v[i-1]);
				dp[i].push_back(temp);
			}
			else{
				dp[i].push_back(dp[i-1][j]);
			}
		}
	}
	display(dp);
	int maxSubSum =  dp.back().back();
	return (total - 2*maxSubSum) ;
}

int main(){
	vector<int> a = {1,6,11,5};
	cout<<minSubsetSumDP(a)<<endl;
	return 0;
}