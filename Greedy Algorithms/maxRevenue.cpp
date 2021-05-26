#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long maximumRevenue(vector<int> a, vector<int> b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long maxVal = 0;
	for(int i=0; i<a.size(); i++){
		maxVal+=(((long long)a[i])*b[i]);
	}
	return maxVal;
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	// vector<int> a = {0,1,5,7}, b={5,1,12, 4};
	cout<<maximumRevenue(a,b);

	return 0;
}