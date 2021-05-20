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

int recur_opt(int w, int capacity, vector<int> weight, int rank, vector<vector<int>> &dp){
	if(w==capacity || weight.size() == 0){
		return w;
	}
	// int og_wsize = weight.size();
	int temp, a, b;
	if(w+weight[0] <=capacity){
		temp = weight[0];
		weight.erase(weight.begin());
		if(dp[weight.size()+1][w+temp] == -1){
			a = recur_opt(w+temp, capacity, weight,dp);
		}
		else{
			a = dp[weight.size()+1][w+temp];
		}
		if(dp[weight.size()+1][w] == -1){
			b = recur_opt(w,capacity,weight,dp);
		}
		else{
			b = dp[weight.size()+1][w];
		}
		// cout<<a<<" "<<b<<endl;
		// display(weight);
		dp[rank][w+temp] = max(a,b);
		return max(a, b);
	}
	return w;

}

int main() {
	int n, W;
	// std::cin >> W >> n;
	// vector<int> w(n);
	// for (int i = 0; i < n; i++) {
	// 	std::cin >> w[i];
	// }

	n = 3;
	W = 10;
	// vector<pair<int,int>> w = {{0,0},{1,1},{2,4},{3,8}};
	vector<int> w = {1,4,8};
	// cout<<dp_op(W, w)<<endl;

	vector<vector<int>> dp(w.size() +1);
	for(int i=0; i<dp.size(); i++){
		for(int j=0; j<=W; j++){
			if(i==0 || j==0){
				dp[i].push_back(0);

			}
			else{
				dp[i].push_back(-1);
			}
		}
	}
	int rank = w.size() +1;
	// cout<<recur_opt(0,W,w,rank,dp)<<endl;

	display(dp);

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
