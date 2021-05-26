#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

template <class T>
void display(vector<T> v){
  for (int i = 0; i < v.size(); ++i){
    std::cout<<v[i]<<" ";
  }
  std::cout<<std::endl;

}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.00, filled = 0.00;

  std::vector<double> vpw;
  for (int i = 0; i < values.size(); ++i){
    vpw.push_back(double(values[i])/double(weights[i]));

  }
  std::vector<double>::iterator result;
  result = std::max_element(vpw.begin(), vpw.end());

  //leaving work -- result is float iterator pointing to a specific array
  // display(vpw);
  while((filled!=capacity) && (values.size() != 0)){
    int maxPos = std::distance(vpw.begin(), result);

    if(weights[maxPos]<=(capacity - filled)){
      
      filled+=weights[maxPos];
      value+=values[maxPos];
      weights.erase(weights.begin()+maxPos);
      values.erase(values.begin()+maxPos);
      vpw.erase(result);
    }
    else{
      value+=(double(capacity)-filled)*vpw[maxPos];
      filled = capacity;
    }
    // display(vpw);
    // std::cout<<maxPos<<" "<<value<<" "<<filled<<" "<<capacity<<"\n";
  
    result = std::max_element(vpw.begin(), vpw.end());

  }

  // std::cout<<"\n"<<std::distance(vpw.begin(), result);

  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  
  // vector<int> values;
  // vector<int> weights;
  // n = 2;
  // capacity = 10;

  // values = {500};
  // weights = {30};

  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;

  return 0;
}
