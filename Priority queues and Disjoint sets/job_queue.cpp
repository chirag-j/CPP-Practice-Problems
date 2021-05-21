#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<pair<int,int>> v){
  for(int i = 0; i<v.size(); i++){
    cout<<v[i].first<<" "<<v[i].second;
    cout<<endl;
  }
}

void siftDown(int i, vector<pair<int,int>> &v){
  int m = i, n = v.size();
  if((n>(2*i + 1)) && (v[2*i + 1].second < v[m].second)){
    m = 2*i + 1;
  }
  if((n>(2*i + 2)) && (v[2*i + 2].second < v[m].second)){
    m = 2*i + 2;
  }
  if(m!=i){
    if(v[2*i + 1].second == v[2*i + 2].second){
      if(v[2*i + 2].first < v[2*i + 1].first){
        m = 2*i + 2;
      }
    }
    swap(v[i], v[m]);
    siftDown(m, v);
  }
  else{
    if((n>(2*i + 1)) && (v[2*i + 1].first < v[m].first)){
      m = 2*i + 1;
    }
    if((n>(2*i + 2)) && (v[2*i + 2].first < v[m].first)){
      m = 2*i + 2;
    }
    if(m!=i){
      swap(v[i], v[m]);
      siftDown(m, v);
    }
  }
}




int main() {
  // std::ios_base::sync_with_stdio(false);
  int num_workers_ = 2, m = 5;
  vector<int> jobs = {1,2,3,4,5};

  // int num_workers_, m;
  // cin >> num_workers_ >> m;
  // vector<int> jobs(m);
  // for(int i = 0; i < m; ++i)
  //   cin >> jobs[i];

  vector<pair<int,int>> threads(num_workers_, {0,0});
  vector<pair<int,int>> assign(m);

  for(int i=0; i<num_workers_; i++){
    threads[i].first = i;
    threads[i].second = 0;
  }

  for(int i=0; i<jobs.size(); i++){
    assign[i] = threads[0];
    threads[0].second+=jobs[i];
    siftDown(0, threads);
  }
  display(assign);


  // JobQueue job_queue;
  // job_queue.Solve();
  return 0;
}
