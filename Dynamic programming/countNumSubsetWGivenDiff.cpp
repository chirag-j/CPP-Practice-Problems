// count number of subsets with given difference
// Target Sum - same problem
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
}

int countSubset(vector<int> a, int diff){
	vector<vector<int>> dp;
	int total = accumulate(a.begin(), a.end(), 0);
	int subsum = (total+diff)/2;
	for(int i=0; i<=a.size(); i++){
		dp.push_back({1});
	}
	for(int i=0; i<subsum; i++){
		dp[0].push_back(0);
	}
	int temp = 0;
	for(int i=1; i<=a.size(); i++){
		for(int j=1; j<=subsum; j++){
			if(j>=a[i-1]){
				dp[i].push_back(dp[i-1][j-a[i-1]] + dp[i-1][j]);
			}
			else{
				dp[i].push_back(dp[i-1][j]);
			}

		}
	}
	display(dp);
	return dp.back().back();
}

int targetSum(vector<int> a, int tarSum){
	return countSubset(a,tarSum);
}


int main(){
	int diff = 1;
	vector<int> a = {1,1,2,3};
	cout<<countSubset(a, diff)<<endl;
	return 0;
}