#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main(){
	int n, num;
	string qtype;
	stack<int> nums, maxnum;
	maxnum.push(0);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>qtype;
		if(qtype=="push"){
			cin>>num;
			nums.push(num);
			maxnum.push(max(num,maxnum.top()));
		}
		else if(qtype == "pop"){
			nums.pop();
			maxnum.pop();
		}
		else{
			cout<<maxnum.top()<<endl;
		}
	}
	return 0;
}