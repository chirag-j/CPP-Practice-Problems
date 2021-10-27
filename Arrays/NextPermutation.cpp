// Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
// Find the largest index l > k such that nums[k] < nums[l].
// Swap nums[k] and nums[l].
// Reverse the sub-array nums[k + 1:].

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k=-1,leftmin;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                k=i;
                break;
            }
        }
        if(k==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        leftmin = k+1;
        for(int i=k+2; i<nums.size(); i++){
            if(nums[leftmin]>=nums[i] && nums[i]>nums[k]){
                leftmin = i;
            }
        }
        swap(nums[k],nums[leftmin]);
        reverse(nums.begin()+k+1, nums.end());
    }
};