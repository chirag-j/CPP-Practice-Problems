#include<iostream>
#include<vector>
using namespace std;
// Choose 3 numbers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: 
// (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) 
// where (0 <= i < j < k < n).

// implementation
// less[0] -- number of lesser elements to the left
// less[1] -- number of lesser elements to the right
// greater[0] -- number of greater elements to the left
// greater[1] -- number of greater elements to the right

// resulting count = less[0]*greater[1] + less[1]*greater[0]

A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
int numTeams(vector<int>& rating) {
    int count = 0;
    for(int i=1; i<rating.size(); i++){
        int less[2] = {}, greater[2] = {};
        for(int j=0; j<rating.size(); j++){
            if(rating[j]<rating[i]){
                less[j>i]++;
            }
            if(rating[j]>rating[i]){
                greater[j>i]++;
            }
        }
        count+=(less[0]*greater[1] + less[1]*greater[0]);
    }
    return count;
}

int main(){
    
    return 0;
}