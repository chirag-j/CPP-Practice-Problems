#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void display(vector<int> v);

int min_oper_recur(int n) {
  if(n==1){
    return 0;
  }

  int a = n%3, b = n%2;

  if(a == 0 && b == 0){
    int x = min(min(min_oper_recur(n/3) +1, min_oper_recur(n/2) +1), min_oper_recur(n-1) +1);
    cout<<x<<" ";
    return x;
  }
  else if(a==0){
    int x = min(min_oper_recur(n/3) +1, min_oper_recur(n-1) +1);
    cout<<x<<" ";
    return x;
  }
  else if(b==0){
    int x = min(min_oper_recur(n/2) +1, min_oper_recur(n-1) +1);
    cout<<x<<" ";
    return x;
  }
  else{
    int x = min_oper_recur(n-1) +1;
    cout<<x<<" ";
    return x;
  }
}

void minOper(int n){
  vector<int> dp = {0,0,1,1}, seq = {n};
  // if(n<=3){
  //   cout<<dp[n]<<endl;
  // }
  int temp, a, b, c;
  for(int i=4; i<=n; i++){
    c = dp[i-1]+1;
    if(i%3==0){
      if(i%2==0){
        temp = min(min(dp[i/2]+1, dp[i/3]+1), dp[i-1]+1);
      }
      else{
        temp = min(dp[i/3]+1, dp[i-1]+1);
      }
    }
    else if(i%2 == 0){
      temp = min(dp[i/2]+1, dp[i-1]+1);
    }
    else{
      temp = dp[i-1]+1;
    }
    dp.push_back(temp);
  }
  
  if(n<=3){
    cout<<dp[n]<<endl;
  }
  else{
    cout<<dp.back()<<endl;
  }
  
  // Trying to find the sequence
  while(n>1){
    c = dp[n-1]+1;
    if(n%3==0){
      a = dp[n/3]+1;
      if(n%2==0){
        b = dp[n/2]+1;
        if(a<=b && a<=c){
          seq.push_back(n/3);
          n/=3;
        }
        else if(b<=a && b<=c){
          seq.push_back(n/2);
          n/=2;  
        }
        else{
          seq.push_back(n-1);
          n-=1;
        }
      }
      else{
        if(a<=c){
          seq.push_back(n/3);
          n/=3;
        }
      } 
    }
    else if(n%2==0){
      b = dp[n/2]+1;
      if(b<=c){
        seq.push_back(n/2);
        n/=2;
      }
      else{
        seq.push_back(n-1);
        n-=1;
      }
    }
    else{
      seq.push_back(n-1);
      n-=1;
    }
  }
  // display(dp);
  reverse(seq.begin(), seq.end());
  
  display(seq);
  // return dp.back();
}

int main() {
  int n;
  // n = 96234;
  std::cin >> n;
  // vector<int> sequence = optimal_sequence(n);
  // std::cout << sequence.size() - 1 << std::endl;
  // n = 5;
  // int y = min_oper_recur(n);

  minOper(n);
}

void display(vector<int> v){
  for(int i = 0; i<v.size(); i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
