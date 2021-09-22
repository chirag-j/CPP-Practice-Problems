#include<iostream>
#include<vector>
using namespace std;

// Question : Every element appears twice except for one. Find that single one.

// XOR operation of any number with 0 gives the number itself.
// XOR operation of same numbers appearing even number of times gives 0.
// Now let's move to the solution part
// As every number comes twice in the array the XOR of all those duplicates will boil down to 0
int main(){
    vector<int> nums = {4,1,2,1,2};
    int num=0;
    for(auto &i : nums) {
        num ^= i;
        cout<<i<<" "<<num<<endl;
    }
    cout<<num;
    return 0;
}