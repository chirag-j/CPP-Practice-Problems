#include <iostream>
#include <limits>
#include <vector>
#include <queue>

// using std::vector;
// using std::queue;
// using std::pair;
// using std::priority_queue;
using namespace std;
template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  distance[s] = 0;
  reachable[s] = 1;
  for(int i = 0; i<adj.size(); i++){
    for(int from = 0; from<adj.size(); from++){
      for(int to=0; to < adj[from].size(); to++){
        if(reachable[from]){reachable[adj[from][to]] = 1;}
        distance[adj[from][to]] = min(distance[adj[from][to]], distance[from] + cost[from][to]);
      }
    }
  }
  for(int i = 0; i<adj.size(); i++){
    for(int from = 0; from<adj.size(); from++){
      for(int to=0; to < adj[from].size(); to++){
        if(distance[from] + cost[from][to] < distance[adj[from][to]]){
          distance[adj[from][to]] = -1e9;
          shortest[adj[from][to]] = 0;
        }
      }
    }
  }
  display(distance);
  display(reachable);
  display(shortest);
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  // vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<long long> distance(n, 1e13);
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
