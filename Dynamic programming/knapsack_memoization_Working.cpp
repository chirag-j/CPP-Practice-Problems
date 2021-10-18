#include <iostream>
#include <vector>

using namespace std;
void display(vector<int> v);
void display(vector<vector<int>> v);

int dp_op(int capacity, vector<int> weight){
	vector<vector<int>> store;
	store.push_back({0});
	for(int i=0; i<capacity; i++){
		store[0].push_back(0);
	}
	for(int i=0; i<weight.size(); i++){
		store.push_back({0});
	}

	int temp;
	// display(store);
	for(int i=1; i<=weight.size(); i++){
		for(int j=1; j<=capacity; j++){
			store[i].push_back(store[i-1][j]);
			if(weight[i-1]<=j){
				temp = store[i-1][j-weight[i-1]] + weight[i-1];
				if(temp>store[i][j]){
					store[i][j] = temp;
				}
			}
			// cout<<i<<" "<<j<<" "<<store[i][j]<<" "<<temp<<endl;
		}
	}
	display(store);
	return store.back().back();
}

int recur_opt(int x, int capacity, vector<int> &weight, vector<vector<int>> &dp){
	if(dp[x][capacity] != -1){return dp[x][capacity];}
	if(x<=0 || weight.size() == 0 || capacity==0){
		return 0;
	}
	int temp = 0;
	if(capacity>=weight[x-1]){
		temp = recur_opt(x-1,capacity-weight[x-1], weight, dp) + weight[x-1];
	}
	dp[x][capacity] = max(temp, recur_opt(x-1,capacity,weight,dp));
	return dp[x][capacity];
}
int main() {
	int n, W;
	// std::cin >> W >> n;
	// vector<int> w(n);
	// for (int i = 0; i < n; i++) {
	// 	std::cin >> w[i];
	// }

	n = 3;
	W = 23;
	// vector<pair<int,int>> w = {{0,0},{1,1},{2,4},{3,8}};
	vector<int> w = {1,4,8,12};
	// cout<<dp_op(W, w)<<endl;

	vector<vector<int>> dp(w.size() +1);
	for(int i=0; i<dp.size(); i++){
		dp[i].assign(W+1, -1);
	}
	dp[0][0] = 1;
	cout<<recur_opt(w.size(),W,w,dp)<<endl;

	display(dp);
	cout<<dp_op(W, w)<<endl;

  // std::cout << optimal_weight(W, w) << '\n';
}

void display(vector<vector<int>> v){
	cout<<"  ";
	for(int i=0; i<v[0].size(); i++){
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i = 0; i<v.size(); i++){
		cout<<i<<" ";
		display(v[i]);
	}
}
void display(vector<int> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
