#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

void dfs(vector<vector<int> > &adj, vector<bool> &used, vector<int> &order, int x) {
  //write your code here
  used[x] = true;
  for(int i: adj[x]){
    if(!used[i]){
      dfs(adj, used, order, i);
    }
  }
  order.push_back(x);
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<bool> used(adj.size(), 0);
  vector<int> order;

  for(int i=0; i<adj.size(); i++){
    if(!used[i]){
      dfs(adj, used, order, i);
    }
  }
  //write your code here
  reverse(order.begin(), order.end());
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
