// Given an array arr[] of N non-negative integers representing the height of blocks. 
// If width of each block is 1, compute how much water can be trapped between 
// the blocks during the rainy season. 


long long trappingWater(int arr[], int n){
    long long water = 0;
    vector<long long> rightMax(n);
    rightMax[n-1] = arr[n-1];
    for(int i=n-2; i>=0;i--){
        rightMax[i] = (rightMax[i+1]>arr[i])? rightMax[i+1]:arr[i];
        // rightMax[i] = max(rightMax[i+1], arr[i]);
    }
    long long leftMax = arr[0];
    for(int i=1; i<n-1; i++){
        if(arr[i]<min(leftMax, rightMax[i+1])){
            water += (min(leftMax, rightMax[i+1]) - arr[i]);
        }
        leftMax = (leftMax>arr[i])? leftMax:arr[i];
    }
    return water;
    // code here
}