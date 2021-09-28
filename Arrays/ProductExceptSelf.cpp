void display(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProd(nums.size());
        vector<int> rightProd(nums.size());
        
        vector<int> result(nums.size());
        int j=nums.size()-1;
        leftProd[0] = nums[0];
        rightProd[j] = nums[j];
        j--;
        for(int i=1; i<nums.size(); i++){
            leftProd[i] = leftProd[i-1] * nums[i];
            rightProd[j] = rightProd[j+1] * nums[j];
            j--;
        }
        // display(leftProd);
        // display(rightProd);
        result[0] = rightProd[1];
        result[nums.size()-1] = leftProd[nums.size()-2];
        for(int i=1; i<nums.size()-1; i++){
            result[i] = leftProd[i-1] * rightProd[i+1];
        }
        return result;
    }
};