#include <iostream>
#include <string>
#include <vector>
using namespace std;
void display(vector<int> v);
void display(vector<vector<int>> v);


int edit_distance(const string &str1, const string &str2) {
  //write your code here
	vector<vector<int>> d;
	for(int i=0; i<str1.size(); i++){

	}
	return 0;
}

int main() {
	string str1;
	string str2;
	// string str1 = "short";
	// string str2 = "ports";
	std::cin >> str1 >> str2;
	// std::cout << edit_distance(str1, str2) << std::endl;
	vector<vector<int>> d ={{0}};
	for(int i=1; i<=str1.size(); i++){
		d[0].push_back(i);
	}
	for(int i = 1; i<=str2.size(); i++){
		d.push_back({i});
	}

	int ins, del, mat;
	for(int i=1; i<=str1.size(); i++){
		for(int j = 1; j<=str2.size(); j++){
			ins = d[j][i-1] +1;
			del = d[j-1][i] +1;
			mat = d[j-1][i-1];
			// cout<<j<<" "<<ins<<" "<<del<<" "<<mat<<endl;
			if(str1[i-1]==str2[j-1]){
				d[j].push_back(min(min(ins,del), mat));
			}
			else{
				d[j].push_back(min(min(ins,del), mat+1));
			}
			// display(d);
		}
	}
	// display(d);
	cout<<d.back().back()<<endl;
	return 0;
}

void display(vector<vector<int>> v){
	for(int i=0; i<v.size(); i++){
		display(v[i]);
	}
}
void display(vector<int> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
