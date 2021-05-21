#include <algorithm>
#include <iostream>
#include <vector>

// using std::vector;
using namespace std;

void display(vector<int> v);

// int get_majority_element(vector<int> &a, int left, int right) {
int get_majority_element(vector<int> &a) {
  sort(a.begin(), a.end());
  // if (left == right) return -1;
  // if (left + 1 == right) return a[left];
  //write your code here
  int count = 1;
  for(int i = 1; i<=a.size(); i++){
    if(a[i]==a[i-1]){
      count++;
    }
    else{
      if(count>a.size()/2){
        return 1;
      }
      else{
        count = 0;
      }
    }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // vector<int> a = {2,3,9,2,2};
  std::cout << get_majority_element(a) << '\n';
}


void display(vector<int> v){
  for(int i = 0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}