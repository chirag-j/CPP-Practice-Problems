#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include<queue>

using namespace std;

double calc_dist(int x1, int y1, int x2, int y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
template<class T>
void display(vector<T> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
void display(vector<vector<double>> v){
  for(int i=0; i<v.size(); i++){
    display(v[i]);
  }
}

template<typename T>
void display(T pq){
  while(!pq.empty()){
    display(pq.top());
    pq.pop();
  }
}

void unionfunc(vector<int> &parent,int x, int y){
  int py = parent[y], px = parent[x];
  
  for(int i=0; i<parent.size(); i++){
    if(parent[i] == py){
      parent[i] = px;
    }
  }
}

int distinct_classes(vector<int> &parent){
  vector<bool> present(parent.size(), false);
  int count = 0;
  for(int i=0; i<parent.size(); i++){
    if(!present[parent[i]]){
      count++;
      present[parent[i]] = true;
    }
  }
  return count;
}

double clustering(vector<int> x, vector<int> y, int k) {
  vector<int> parent(x.size());
  // vector<vector<double>> dist(x.size());
  auto compare = [](vector<double> a, vector<double> b){
    return a[2] > b[2];
  };
  priority_queue<vector<double>, vector<vector<double>>, decltype(compare)> edges(compare);
  

  for(double i=0; i<x.size(); i++){
    parent[i] = i;
    for(double j=i+1; j<x.size(); j++){
      edges.push({i,j,calc_dist(x[i],y[i],x[j],y[j])});
    }
  }

  while(!edges.empty()){
    vector<double> temp = edges.top();
    if(parent[temp[0]] == parent[temp[1]]){
      edges.pop();
      continue;
    }
    unionfunc(parent, int(temp[0]),int(temp[1]));
    edges.pop();
    // cout<<distinct_classes(parent)<<endl;
    // display(edges.top());
    // display(parent);
    if(distinct_classes(parent) == k){
      break;
    }
  }
  while(!edges.empty()){
    vector<double> temp = edges.top();
    if(parent[temp[0]] == parent[temp[1]]){
      edges.pop();
    }
    else{break;}
  }
  // display(edges.top());

  // display(edges);


  // display(dist);
  return edges.top()[2];
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
