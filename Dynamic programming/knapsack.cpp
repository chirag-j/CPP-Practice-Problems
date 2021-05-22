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

int recur_opt(int w, int capacity, vector<int> weight){
	if(w==capacity || weight.size() == 0){
		return w;
	}
	int temp, a, b;
	for(int i=0; i<weight.size(); i++){
		if(w+weight[i] <=capacity){
			temp = weight[i];
			weight.erase(weight.begin()+i);
			a = recur_opt(w+temp, capacity, weight);
			b = recur_opt(w,capacity,weight);
			// cout<<a<<" "<<b<<endl;
			// display(weight);
			return max(a, b);
		}
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
	vector<int> w = {1,1,3,8};
	cout<<dp_op(W, w)<<endl;
	// cout<<recur_opt(0,W,w)<<endl;



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
