// Given an array of integers arr, find the sum of min(b), 
// where b ranges over every (contiguous) subarray of arr. 
// Since the answer may be large, return the answer modulo 109 + 7.

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st = {};
    
//         Find next lesser element to the left, store the index in left[i]
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        left[i] = (!st.empty())? st.top():-1;
        st.push(i);
    }
    while(!st.empty()){
        st.pop();           //flush
    }

//         Find next lesser element to the right, store the index in right[i]
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        right[i] = (!st.empty())? st.top():n;
        st.push(i);
    }
    long long int x, y, p = 1e9+7;
    long long int sum = 0;
    // display(left);
    // display(right);
    for(int i=0; i<n;i++){
        x = i-left[i];
        y = right[i]-i;
        sum=(sum + (x*y*arr[i])%p)%p;
    }
    return sum;
}