// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
// return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, 
// which means you could search circularly to find its next greater number. 
// If it doesn't exist, return -1 for this number.

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]



vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> res(n,-1);
    for(int i=n-1; i>=0; i--){
        while(!stk.empty() && stk.top()<=nums[i]){stk.pop();}
        res[i] = (stk.empty())? -1:stk.top();
        stk.push(nums[i]);
    }
    for(int i=n-1; i>=0; i--){
        while(!stk.empty() && stk.top()<=nums[i]){stk.pop();}
        res[i] = (stk.empty() || res[i]!=-1)? res[i]:stk.top();
        stk.push(nums[i]);
    }
    return res;
}