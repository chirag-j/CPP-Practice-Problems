
// rod cutting problem

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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

int cutrod(int price[], int n){
	// vector<int> pvec(price, price+n);
	vector<vector<int>> dp;
	for(int i=0; i<=n; i++){
		dp.push_back({0});
	}
	for(int i=0; i<n; i++){
		dp[0].push_back(0);
	}
	int temp = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(j>=i){
				temp = dp[i][j-i] + price[i-1];
				dp[i].push_back(max(dp[i-1][j], temp));
			}
			else{
				dp[i].push_back(dp[i-1][j]);
			}
		}
	}
	return dp.back().back();
}

int main(){
	int n = 8;
	int price[] = {1,5,8,9,10,17,17,20};

	cout<<cutrod(price, n);
	return 0;
}