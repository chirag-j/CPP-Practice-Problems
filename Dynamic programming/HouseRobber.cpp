// Given an integer array nums, return the max sum possible by picking numbers
// from the array such that numbers picked is NOT be adjacent

// Input: nums = [1,2,3,1]
// Output: 4 (1+3)

// Input: nums = [2,7,9,3,1]
// Output: 12  (2+9+1)

vector<int> dp;
class Solution {
public:
    
    int robrecur(vector<int>& nums, int x, int res){
        if(x>nums.size()-1){
            return res;
        }
        if(dp[x] != -1){
            return res + dp[x];
        }
        dp[x] =  max(robrecur(nums,x+1, res), robrecur(nums,x+2, res+nums[x]));
        return dp[x];
    }
    
    int rob(vector<int>& nums) {
        dp.assign(nums.size()+1, -1);
        return robrecur(nums, 0, 0);
    }
};