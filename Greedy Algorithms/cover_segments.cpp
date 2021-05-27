#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<pair<int,int>> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
}
bool comSort(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}

// vector<pair<int,int>> Merge(vector<pair<int,int>> A, vector<pair<int,int>> A){
// 	while(A)
// }

// vector<pair<int,int>> mergeSort(vector<pair<int,int>> segment){
// 	if(segment.size() == 1){
// 		return segment;
// 	}
// 	int mid = segment.size()/2;
// 	vector<pair<int,int>> A(segment.begin(),segment.begin()+mid), B(segment.begin()+mid, segment.end());
// 	A = mergeSort(A);
// 	B = mergeSort(B);
// 	C = Merge(A,B);
// }

bool liesBetween(int a, pair<int, int> p){
	return (p.first<=a && p.second>=a);
}

void findCommonPoints(vector<pair<int,int>> segment){
	vector<pair<int,int>> temp;
	bool found = false;
	for(int i=0; i<segment.size(); i++){
		found = false;
		for(int j=0; j<temp.size(); j++){
			if(liesBetween(segment[i].first, temp[j])){
				temp[j] = {max(segment[i].first, temp[j].first), min(segment[i].second, temp[j].second)};
				found = true;
				break;
			}
		}
		
		if(!found){
			temp.push_back(segment[i]);
		}
	}
	cout<<temp.size()<<endl;
	for(int i=0; i<temp.size(); i++){
		cout<<temp[i].first<<" ";
	}
	cout<<endl;

}

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> segment(n);
	for(int i=0; i<n; i++){
		cin>>segment[i].first>>segment[i].second;
	}
	// vector<pair<int,int>> segment = {{5,6},{2,5},{1,3},{4,7}};
	sort(segment.begin(), segment.end(),comSort);
	// display(segment);
	findCommonPoints(segment);
	return 0;
}