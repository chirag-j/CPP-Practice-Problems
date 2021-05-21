#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void siftDown(int i, vector<int> &data_, vector< pair<int, int> > &swaps_){
	// cout<<"yo "<<i<<" ";
	int m = i, n = data_.size();
	if((n>(2*i + 1)) && (data_[2*i + 1]<data_[m])){
		m = 2*i + 1;
	}
	if((n>(2*i + 2)) && (data_[2*i + 2]<data_[m])){
		m = 2*i + 2;
	}
	if(m!=i){
		swap(data_[i], data_[m]);
		swaps_.push_back({i, m});
		siftDown(m, data_, swaps_);
	}
}

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
    // data_ = {5,4,3,2,1};
  }


  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    // for (int i = 0; i < data_.size(); ++i)
    //   for (int j = i + 1; j < data_.size(); ++j) {
    //     if (data_[i] > data_[j]) {
    //       swap(data_[i], data_[j]);
    //       swaps_.push_back(make_pair(i, j));
    //     }
    //   }
    // display(data_);
    int n = data_.size();
  	for(int i = ((n-2)/2); i>=0; i--){
  		// cout<<i;
  		siftDown(i, data_, swaps_);
	  	// display(data_);
  	}
  	// for(int i=0; i<swaps_.size(); i++){
  	// 	cout<<swaps_[i].first<<" "<<swaps_[i].second<<"\n";
  	// }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
