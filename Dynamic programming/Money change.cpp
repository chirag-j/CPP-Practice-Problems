#include <iostream>
#include<vector>
using namespace std;
void display(vector<int> v);

int get_change(int m) {
  //write your code here
	// for(int i = 0; i<d.size(); i++){
	// 	if(m%d[i] == 0){
	// 		return m/d[i];
	// 	}
	// }
	vector<int> c = {0,1,2,1,1};
	if(m<5){
		return c[m];
	}

	int temp = 0;
	for (int i=5; i<=m; i++){
		temp = min(min(c[i-1]+1,c[i-3]+1), c[i-4]+1);
		c.push_back(temp);
	}

	// display(c);
  return c.back();
}

int main() {
  int m;
  // m = 34;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

void display(vector<int> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
