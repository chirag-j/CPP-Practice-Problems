#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

bool bipartite(vector<vector<int> > &adj, queue<int> &que, vector<bool> &visited, vector<bool> &color) {
  //write your code here
  if(que.size() == 0){
    return true;
  }
  int x = que.front();
  if(adj[x].size() != 0){
    for(int i: adj[x]){
      if(!visited[i]){
        que.push(i);
        visited[i] = true;
        color[i] = !color[x];
      }
      else{
        if(color[i] == color[x]){
          return false;
        }
      }
    }
  }
  que.pop();
  if(!bipartite(adj, que, visited, color)){
    return false;
  }
  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  vector<bool> visited(adj.size(), false);
  vector<bool> color(adj.size(), false);
  queue<int> que;
  que.push(0);
  visited[0] = true;
  std::cout << bipartite(adj, que, visited, color)<<endl;
  display(color);
  return 0;
}
