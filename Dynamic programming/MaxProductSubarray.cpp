// Given an integer array nums, 
// find a contiguous non-empty subarray within the array that has the largest product, 
// and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.



class Solution {
public:
//     int recur(vector<int>& nums, int x, int y){ 
//         if(x>y || x>=nums.size() || y>=nums.size()){return INT_MIN;}
//         // int temp = nums[x], opt=temp;
//         // for(int i = x+1; i<=y; i++){
//         //     temp *= nums[i];
//         //     opt = max(temp, opt);
//         //     if(temp==0){break;}
//         // }
//         // if(x<y)
//         return max(max(recur(nums, x+1, y), recur(nums, x, y+1)), prod[x][y]); 
        
//     }
    int maxProduct(vector<int>& nums) {
        int max_here = nums[0], min_here = nums[0], lmax, lmin, max_so_far = nums[0];
        for(int i=1; i<nums.size(); i++){
            lmax = max(max(max_here*nums[i], min_here*nums[i]), nums[i]);
            lmin = min(min(max_here*nums[i], min_here*nums[i]), nums[i]);
            
            max_so_far = max(lmax, max_so_far);
            max_here = lmax;
            min_here = lmin;
            cout<<lmax<<" "<<lmin<<" "<<max_here<<" "<<min_here<<" "<<max_so_far<<endl;
        }
        return max_so_far;   
    }
};