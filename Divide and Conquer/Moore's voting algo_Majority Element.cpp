// majority element is one which occurs strictly more than half the length of array

int majorityElement(vector<int>& nums) {
    int ansIndex = 0;
    int count = 1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==nums[ansIndex]){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            ansIndex = i;
            count = 1;
        }
    }
    return nums[ansIndex];
}