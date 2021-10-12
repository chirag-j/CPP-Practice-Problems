// QUestion : Given an array of integers nums and an integer k, 
// return the total number of continuous subarrays whose sum equals to k.

// generate cumulative_sum search for an older sum and subtract to see if it matches target
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