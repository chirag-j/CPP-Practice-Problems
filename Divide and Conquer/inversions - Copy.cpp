#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> v);

vector<int> merge(vector<int> &A, vector<int> &B, long long &inv){
	vector<int> C;
	int x = B.size();
	while(A.size()>0 || B.size()>0){
		if(A.size() == 0){
			C.insert(C.end(), B.begin(), B.end());
			B.erase(B.begin(), B.end());
		}
		else if(B.size() == 0){
			// if(A.size()>1){
			// 	// inv+=(A.size()-1) *x;
			// }
			C.insert(C.end(), A.begin(), A.end());
			A.erase(A.begin(), A.end());
		}
		else if(A[0]>B[0]){
			inv+=A.size();
			C.push_back(B[0]);
			B.erase(B.begin());
		}
		else{
			C.push_back(A[0]);
			A.erase(A.begin());
		}
	}
	return C;
}

vector<int> mergeSort(vector<int> &a, long long &inv) {
	if(a.size() == 1){
		return a;
	}
  vector<int> A, B, C;
  vector<int> al, ar;

  int mid = a.size()/2;
  al.insert(al.begin(), a.begin(), a.begin()+mid);
  ar.insert(ar.begin(), a.begin()+mid, a.end());
  A = mergeSort(al, inv);
  B = mergeSort(ar, inv);
  C = merge(A, B, inv);
	// display(C);
	// cout<<inv<<endl;
  return C;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  // vector<int> a = {5,4,3,2,1};
  vector<int> b(a.size());
  long long inv = 0;
  b = mergeSort(a, inv);
  // display(b);
  cout<<inv<<endl;
  // vector<int> x = {2,6,9,11}, y ={3,5,10,12,13}, z;
  // z = merge(x, y);
  // display(z);
  // display(mergeSort(a, 0, a.size()))
}


void display(vector<int> v){
  for(int i = 0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
