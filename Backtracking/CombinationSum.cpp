// Given an array of distinct integers candidates and a target integer target, 
// return a list of all unique combinations of candidates where the chosen numbers sum to target. 
// You may return the combinations in any order

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Approach
// Notice the parameter 'start'
// Once we insert a number i, only insert numbers from i and beyond, (not i-1 to 0)
// This ensures that we end up with only unique combinations

vector<vector<int>> res;
class Solution {
public:
    void recurcomb(vector<int>& candidates, int target, vector<int> curr, int x){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i=x; i<candidates.size(); i++){
            if(target>=candidates[i]){
                curr.push_back(candidates[i]);
                recurcomb(candidates, target-candidates[i], curr, i);
                curr.pop_back();
            }
            else{break;}
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        recurcomb(candidates, target, {}, 0);
        return res;
    }
};