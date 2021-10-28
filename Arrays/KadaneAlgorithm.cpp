// Given an array Arr[] of N integers. 
// Find the contiguous sub-array(containing at least one number) 
// which has the maximum sum and return its sum.

// Kadane's Algorithm
long long maxSubarraySum(int arr[], int n){
    long long max_so_far = arr[0], max_end_here = 0;
    for(int i=0; i<n; i++){
        max_end_here+=arr[i];
        max_so_far = max(max_so_far, max_end_here);
        if(max_end_here<0){
            max_end_here = 0;
        }
    }
    return max_so_far;
    
}