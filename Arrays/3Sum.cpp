
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Solution explanation - Use two pointers concept
// First sort the array
// keep -nums[i] as the required value in each iteration
// Now keep one pointer at i+1, and 1 at the end of the array
// if 
// or if it more, decrease the second posum of values at both pointer is equal, insert into a setinter
// else if it is less, increase the first pointer




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // nums = {0,0,0,0};
        vector<vector<int>> result;
        result.clear();
        set<vector<int>> setvec;        //set will store the unique vectors, provided they are sorted
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