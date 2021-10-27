// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node


// DP solution
vector<vector<int>> dp;
vector<vector<int>> maxi;
class Solution {
public:
    int recurSol(vector<int>& arr, int left, int right){
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        if(left==right){
            return 0;
        }
        int res = INT_MAX;
        for(int i=left; i<right; i++){
            res = min(res, recurSol(arr, left,i) + recurSol(arr,i+1,right) + maxi[left][i]*maxi[i+1][right]);
        }
        dp[left][right] = res;
        return res;
    }
    int mctFromLeafValues(vector<int>& arr) {
        maxi.assign(arr.size(), vector<int> (arr.size()));
        dp.assign(arr.size(), vector<int> (arr.size(),-1));
        for(int i=0; i<arr.size(); i++){
            maxi[i][i] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[i][j] = max(maxi[i][j-1], arr[j]);
            }
        }
        return recurSol(arr,0,arr.size()-1);
    }
};

// Greedy solution
// Approach 2 (Greedy+ Linked list)

// Pick up the minimum element in the array (val1)
// Check their neighbors (left and right) and choose the minimum value betweem them (val2)
// Accumulate this product to your answer (ans+=val1*val2) then delete the element (val1) in step 1.
// Repeat it until there is one element in the array.
int mctFromLeafValues(vector<int>& arr) {
//        Greedy approach
    list<int> alist(arr.begin(), arr.end());
    auto minEl = alist.begin();
    int x,y,res=0;
    while(alist.size()>1){
        minEl = alist.begin();
        for(auto itr = alist.begin(); itr!=alist.end(); itr++){
            minEl = (*minEl > *itr)? itr:minEl;
        }
        if(minEl != alist.begin()){
            x = *(--minEl);
            minEl++;
        }
        else{x = INT_MAX;}
        y = (++minEl != alist.end())? *minEl:INT_MAX;
        minEl--;
        
        res+=(*minEl)*min(x,y);
        // cout/
        alist.erase(minEl);
    }
    return res;
}