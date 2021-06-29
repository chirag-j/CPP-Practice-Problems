#include <iostream>
#include <vector>

using namespace std;
void display(vector<int> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
void display(vector<vector<int>> v){
  for(int i=0;i<v.size(); i++){
    display(v[i]);
  }
}
vector<int> ids;
void reach(vector<vector<int> > &adj, int x, int id) {
  for(int i=0; i<adj[x].size(); i++){
    if(ids[adj[x][i]] == -1){
      ids[adj[x][i]] = id;
      reach(adj, adj[x][i], id);
    }
  }
}

int main() {
  size_t n, m;
  // cout<<"Enter stuff: ";
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  ids.assign(adj.size(), -1);
  int x, y;
  std::cin >> x >> y;
  for(int i=0; i<ids.size(); i++){
    if(ids[i]==-1){
      ids[i] = i;
      reach(adj, i, i);
    }
  }
  // display(ids);
  if(ids[x-1] == ids[y-1]){
    cout<<1;
  }
  else{
    cout<<0;
  }
  // std::cout << reach(adj, x - 1, y - 1);
  // display(adj);
}
