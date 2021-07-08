#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" " ; 
  }
  cout<<endl;
}

void bfs(vector<vector<int>> &adj, queue<int> &que, vector<bool> &visited, vector<int> &layer){
  if(que.size() == 0){
    return;
  }
  int x = que.front();
  for(int i=0; i<adj[x].size(); i++){
    if(!visited[adj[x][i]]){
      visited[adj[x][i]] = true;
      layer[adj[x][i]] = layer[x] +1;
      que.push(adj[x][i]);
    }
  }
  que.pop();
  bfs(adj, que, visited, layer);
}

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<bool> visited(adj.size(), false);
  vector<int> layer(adj.size(), 0);
  queue<int> que;
  que.push(s);
  visited[s] = true;
  bfs(adj, que, visited, layer);

  if(layer[t] == 0){ 
    layer[t] = -1;

  }
  // display(layer);
  return layer[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;

  std::cout << distance(adj, s, t);
  return 0;
}