#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// using std::vector;
// using std::queue;
// using std::pair;
// using std::priority_queue;
template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

template<class T>
void display(vector<vector<T>> v){
  for(int i=0; i<v.size(); i++){
    display(v[i]);
  }
  cout<<endl;
}
template<typename T>
void display_pq(T pq){
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
  cout<<endl;
}
long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  auto compare = [](pair<int, long long> a, pair<int, long long> b){
    return a.second > b.second;
  };

  priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(compare)> pq(compare);
  vector<bool> visited(adj.size(), false);
  vector<long long> dist(adj.size(), -1);
  dist[s] = 0;
  // visited[s] = true;
  pq.push({s, 0});
  while(!pq.empty()){
    int x = pq.top().first;
    // if(dist[x]<pq.top().second){
    //   pq.pop();
    //   continue;
    // }
    if(visited[x]){
      pq.pop();
      continue;
    }
    // cout<<x<<" "<<dist[x]<<endl;
    for(int i=0; i<adj[x].size(); i++){
      if(!visited[adj[x][i]]){
        if(dist[adj[x][i]] == -1){          //first time ha>
          dist[adj[x][i]] = dist[x] + cost[x][i];
        }
        else{
          dist[adj[x][i]] = min(dist[adj[x][i]], dist[x] + cost[x][i]);
        }
        pq.push({adj[x][i], dist[adj[x][i]]});
      }
    }
    visited[x] = true;
    if(visited[t]){break;}
    pq.pop();
  }
  // display(dist);
  return dist[t];
}

// struct customComparator{
//   bool operator()
// }

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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  // priority_queue<pair<int, long long>, vector<int>, decltype(compare)> pq(compare);
  // for(int i : {10,4,2,7,20}){
  //   pq.push(i);
  // }
  // display_pq(pq);
  // display(adj);
  // display(cost);
  std::cout << distance(adj, cost, s, t);
  return 0;
}
