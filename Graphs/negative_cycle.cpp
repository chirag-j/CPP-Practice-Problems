#include <iostream>
#include <vector>

// using std::vector;
using namespace std;
template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
int negative_cycle(vector<vector<int>> &adj, vector<vector<int> > &cost) {
  //write your code here
  vector<int> dist(adj.size(), 1e9);
  dist[0] = 0;
  for(int i = 0; i<adj.size(); i++){
    for(int from = 0; from<adj.size(); from++){
      for(int to=0; to < adj[from].size(); to++){
        dist[adj[from][to]] = min(dist[adj[from][to]], dist[from] + cost[from][to]);
      }
    }
  }
  for(int i = 0; i<adj.size(); i++){
    for(int from = 0; from<adj.size(); from++){
      for(int to=0; to < adj[from].size(); to++){
        if(dist[from] + cost[from][to] < dist[adj[from][to]]){
          return 1;
        }
      }
    }
  }
  // display(dist);
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
