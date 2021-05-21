#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a,int low, int high, int x) {
  // int left = 0, right = (int)a.size(), mid;

  int mid = int(low + (high-low)/2);
  // std::cout<<"Mid "<<mid<<std::endl;
  if(low>high){
  	return -1;
  }

  if(x == a[mid]){
  	return mid;
  }
  else if(x>a[mid]){
  	return binary_search(a, mid+1, high, x);
  }
  else{	
  	return binary_search(a, low, mid-1, x);
  }
  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;

  std::cin>>n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin>>a[i];
  }
  int m;
  std::cin>>m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin>>b[i];
  }

  //
  // n = 5;
  // int m = 5;
  // vector<int> a = {1,5,8,12,13}, b = {8,1,23,1,11};
  //
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a,0, a.size()-1, b[i]) << ' ';
  }
}
