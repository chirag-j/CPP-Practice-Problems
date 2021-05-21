#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void display(vector<int> v);

vector<int> partition3(vector<int> &a, int l, int r){
  int x = a[l];
  vector<int> m = {l, l};
  int &m1 = m[0], &m2 = m[1];
  // cout<<a[l]<<endl;
  // cout<<"before partition3 ";
  // display(a);
  for (int i = l + 1; i <= r; i++) {
    // cout<<i<<" "<<m1<<" "<<m2<<" "<<endl;
    if (a[i] < x) {
      // m1++;
      if(m2+1 == i){
        swap(a[m1], a[i]);
      }
      else{
        swap(a[m1], a[m2+1]);
        swap(a[m1], a[i]);
      }
      m1++;
      m2++;
    }
    else if(a[i] == x){
      m2++;
      swap(a[i], a[m2]);
    }
    // display(a);
  }
  // swap(a[l], a[m1-1]);
  // cout<<"after partition3 ";
  // display(a);
  // display(m);
  return m;

}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // vector<int> a = {9,4,4,6,10,9};
  // vector<int> a = {9,4,4,6,9,12};
  randomized_quick_sort(a, 0, a.size() - 1);
  display(a);
  // int m = partition2(a, 0, a.size()-1);
  // display(a);
  // vector<int> mx = partition3(a, 0, a.size()-1);
  // display(a);
  // display(mx);
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cout << a[i] << ' ';
  // }
}
void display(vector<int> v){
  for(int i = 0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
