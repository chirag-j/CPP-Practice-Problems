
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // nums = {0,0,0,0};
        vector<vector<int>> result;
        result.clear();
        set<vector<int>> setvec;
        // unordered_set<vector<int>, >
        sort(nums.begin(), nums.end());
        // return {nums};
        for(int i=0; i<nums.size(); i++){
            int x = i+1, y = nums.size()-1;
            int req = -nums[i];
            while(y>x){
                if(nums[x]+nums[y] == req){
                    setvec.insert({nums[i],nums[x],nums[y]});
                    x++;
                    y--;
                }
                else if(nums[x]+nums[y] > req){
                    y--;
                }
                else{
                    x++;
                }
            }
            
        }
        for(auto &itr : setvec){
            result.push_back(itr);
        }
        return result;
        
    }
};