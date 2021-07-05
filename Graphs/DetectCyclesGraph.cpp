#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
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

vector<int> pre, post;
vector<bool> visited, recSt;

bool dfs(vector<vector<int>> &adj, int x, int &clock){
  // if(recSt[x] == true){
  //   cout<<"cycle detected"<<endl;
  // }
  recSt[x] = true;
  clock++;
  visited[x] = true;
  pre[x] = clock;
  for(int i: adj[x]){
    if(!visited[i]){
      // clock++;
      if(!dfs(adj, i, clock)){
        return false;
      }
    }
    else if(recSt[i]){
      return false;
      cout<<"cycle detected"<<endl;
      display(recSt);
    }
  }
  recSt[x] = false;
  clock++;
  post[x] = clock;
  // clock++;
  return true;
}


int acyclic(vector<vector<int> > &adj) {

  //write your code here
  return 0;
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
  pre.assign(adj.size(),0);
  post.assign(adj.size(),0);
  visited.assign(adj.size(),false);
  recSt.assign(adj.size(),false);
  // std::cout << acyclic(adj);
  int clock = 0;
  // adj = reverseGraph(adj);


  //Assignment code begins here
  // post and pre visit numbers were not needed to compute cyclicity
  for(int i=0; i<adj.size(); i++){
    if(!visited[i])
      if(!dfs(adj, i, clock)){
        cout<<1<<endl;
        return 0;
      }
  }
  cout<<0<<endl;
  // display(pre);
  // display(post);
  return 0;
}
