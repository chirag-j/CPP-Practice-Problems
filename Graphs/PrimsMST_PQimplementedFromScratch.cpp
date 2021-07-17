#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include<queue>
#include<numeric>
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
// template<class T>
void display(vector<pair<int, double>> v){
  for(int i=0; i<v.size(); i++){
    cout<<v[i].first<<"-"<<v[i].second<<" ";
  }
  cout<<endl;
}
// template<typename T>
// void display_pq(T pq){
//   while(!pq.empty()){
//     cout<<pq.top().first<<" ";
//     pq.pop();
//   }
//   cout<<endl;
// }
int parent(int i){
   return (i-1)/2;
}

int leftChild(int i){
  return 2*i+1;
}

int rightChild(int i){
  return 2*i+2;
}

void siftUp(vector<pair<int, double>> &pq, int i){
  if(pq.empty()){return;}

  while(i!=0 && pq[parent(i)].second > pq[i].second){
    swap(pq[parent(i)], pq[i]);
    i = parent(i);
  }
}

void siftDown(vector<pair<int, double>> &pq, int i){
  if(pq.empty()){
    return;
  }
  int minInd = i, len = pq.size();
  if(leftChild(i)<len && pq[leftChild(i)].second < pq[minInd].second){
    minInd = leftChild(i);
  }
  if(rightChild(i)<len && pq[rightChild(i)].second < pq[minInd].second){
    minInd = rightChild(i);
  }
  if(minInd != i){
    swap(pq[minInd], pq[i]);
    siftDown(pq, minInd);
  }
}

void insert(vector<pair<int, double>> &pq, int x, double cost){
  // cout<<x<<" "<<cost<<endl;
  pq.push_back({x, cost});
  siftUp(pq, pq.size()-1);
}

void change_priority(vector<pair<int, double>> &pq, int x, double new_cost){
  for(int i=0; i<pq.size(); i++){
    if(pq[i].first == x){
      if(pq[i].second > new_cost){
        pq[i].second = new_cost;
        siftUp(pq, i);
      }
      else{
        pq[i].second = new_cost;
        siftDown(pq, i);
      }
      break;
    }
  }
}

void extractMax(vector<pair<int, double>> &pq){
  if(pq.size() == 0){
    return;
  }
  swap(pq[0],pq[pq.size()-1]);
  pq.pop_back();
  siftDown(pq, 0);
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  vector<double> cost(x.size(), 1e9);
  vector<int> pt(x.size(), -1);
  vector<bool> visited(x.size(), false);
  vector<pair<int,double>> pq_vec;
  cost[0] = 0.;
  pt[0] = 0;
  for(int i=0; i<x.size(); i++){
    insert(pq_vec, i, cost[i]);
  }
  // display(pq_vec);
  while(!pq_vec.empty()){
    int z = pq_vec[0].first;

    visited[z] = true;
    extractMax(pq_vec);
    // cout<<z<<endl;
    // display(pq_vec);
    for(int i=0; i<x.size(); i++){
      if(!visited[i] && i!=z){
        double dist = calc_dist(x[z], y[z], x[i], y[i]);
        if(cost[i] > dist){
          cost[i] = dist;
          change_priority(pq_vec, i, cost[i]);
          pt[i] = z;
          // pq.push({i, cost[i]});
        }
      }
    }
  }
  // display(cost);
  // display(pt);
  result = accumulate(cost.begin(), cost.end(), result);
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
  // cout<<calc_dist(0,0,3,2);
  // vector<pair<int,double>> pq_vec;
  // vector<double> cost(x.size(), 1e9);
  // int z = 0;
  // cost[0] = 0;
  // for(int i=0; i<x.size(); i++){
  //   insert(pq_vec, i, cost[i]);
  // }
  // for(int i=0; i<x.size(); i++){
  //   if(i!=z){
  //     double dist = calc_dist(x[z], y[z], x[i], y[i]);
  //     if(cost[i] > dist){
  //       cost[i] = dist;
  //       change_priority(pq_vec, i, cost[i]);
  //       // pq.push({i, cost[i]});
  //     }
  //   }
  // }
  // display(pq_vec);
  // extractMax(pq_vec);
  // display(pq_vec);

  // cout<<n;
  // for(int i=0; i<x.size(); i++){
  //   insert(pq_vec, 1, 1e9);
  // }
  // pq_vec.push_back({0,1e9});
  // pq_vec.push_back({1,1e7});
  // display(pq_vec);
  // change_priority(pq_vec, 1, 20);
  // display(pq_vec);
  // extractMax(pq_vec);
  // display(pq_vec);
  
}
