#include<iostream>
#include<vector>
using namespace std;
// Given an integer array nums, return true if 
// there exists a triple of indices (i, j, k) such that 
// i < j < k and nums[i] < nums[j] < nums[k]. 
// If no such indices exists, return false.

// best Solution
bool increasingTriplet(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    for (int x : nums) {
        if (x <= c1) {
            c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
        } else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
            c2 = x;           // x is better than the current c2, store it
        } else {              // here when we have/had c1 < c2 already and x > c2
            return true;      // the increasing subsequence of 3 elements exists
        }
    }
    return false;
}



bool increasingTriplet(vector<int>& nums) {
    int n = nums.size() -1;
    vector<int> rightMax(nums.size());
    rightMax[n] = nums[n];
    for(int i=n-1; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], nums[i]);
    }
    // for(int i=0; i<=n; i++){
    //     cout<<rightMax[i]<<" ";
    // }
    // cout<<endl;
    int leftMin = INT_MAX;
    for(int i=0; i<=n; i++){
        if(leftMin < nums[i] && rightMax[i] > nums[i]){
            return true;
        }
        leftMin = min(leftMin, nums[i]);
        // cout<<leftMin<<" ";
    }
    cout<<endl;
    return false;
}
int main(){
    
    return 0;
}