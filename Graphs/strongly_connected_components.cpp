#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

int maxInd(vector<int> v){
  int maxI = 0;
  for(int i=0; i<v.size(); i++){
    maxI = (v[i]>v[maxI]) ? i:maxI;
  }
  return maxI;
}

vector<vector<int>> reverseGraph(vector<vector<int> > adj){
  vector<vector<int>> Radj(adj.size());
  for(int i=0; i<adj.size(); i++){
    for(int v: adj[i]){
      Radj[v].push_back(i);
    }
  }
  return Radj;
}

void dfs(vector<vector<int>> &adj, int x, vector<bool> &visited, vector<int> &post){
  visited[x] = true;
  post[x] = 0;
  for(int i: adj[x]){
    if(!visited[i]){
      dfs(adj, i, visited, post);
    }
  }
}

void dfs(vector<vector<int>> &adj, int x, int &clock, vector<int> &pre, vector<int> &post, vector<bool> &visited){
  visited[x] = true;
  clock++;
  pre[x] = clock;
  for(int i: adj[x]){
    if(!visited[i]){
      dfs(adj, i, clock, pre, post, visited);
    }
  }
  clock++;
  post[x] = clock;
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  return result;
}

int main() {
  size_t n, m;
  // cout<<"Waiting for input";
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }

  vector<vector<int>> Radj = reverseGraph(adj);

  vector<int> pre(adj.size(),0), post(adj.size(),0);
  vector<bool> visited(adj.size(),false);
  int clock = 0;

  for(int i=0; i<Radj.size(); i++){
    if(!visited[i])
      dfs(Radj, i, clock, pre, post, visited);
  }
  // display(pre);
  // display(post);
  visited.assign(adj.size(),false);
  // std::cout << number_of_strongly_connected_components(adj);
  int SCC = 0;
  for(int i=0; i<adj.size(); i++){
    int mi = maxInd(post);
    if(!visited[mi]){
      SCC++;
      dfs(adj, mi, visited, post);
    }
    else{break;}
  }
  cout<<SCC<<endl;
  return 0;
}
