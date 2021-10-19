// QUestion : Given an array of integers nums and an integer k, 
// return the total number of continuous subarrays whose sum equals to k.

// generate cumulative_sum search for an older sum and subtract to see if it matches target
// property -> sum from i to j = cum_sum(0,i) - cum_sum(0,j)

// we're storing cum_sum(0,i) for al i's in a hash table
// we want sum = k, so, cum_sum(0,i) - cum_sum(0,j) = k;
// or, we can say, if cum_sum(0,j) exists, such that cum_sum(0,i)-k = cum_sum(0,j),
// then we have found sum from i to j = k;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, sum = 0;
        unordered_map<int, int> cum_sum;
        // vector<int> cum_sum(n+1);
        // cum_sum[0] = 0;
        // cum_sum[1] = nums[0];
        // for(int i=0; i<n; i++){
        //     cum_sum[i+1] = cum_sum[i] + nums[i];
        // }
        // display(cum_sum);
        cum_sum[0] = 1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(cum_sum.find(sum-k)!=cum_sum.end()){
                count+=cum_sum[sum-k];
            }
            cum_sum[sum]++;
        }
        return count;
    }
};


////Longest Sub-Array with Sum K
// Given an array containing N integers and an integer K.,
// find the length of the longest Sub-Array with the sum of the elements equal to the given value K.
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) { 
        // Complete the function
        unordered_map<int, int> cum_sum;
        int sum = 0, maxL = 0;
        cum_sum[0] = 0;
        for(int i=0; i<N; i++){
            sum+=A[i];
            if(cum_sum.find(sum-K) != cum_sum.end()){
                maxL = max(maxL, (i+1 - cum_sum[sum-K]));
            }
            if(cum_sum.find(sum) == cum_sum.end()){
                cum_sum[sum] = i+1;
            }
        }
        return maxL;
    } 

};