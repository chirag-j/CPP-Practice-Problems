// Given an array A[] of size N and a positive integer K, 
// find the first negative integer for each and every 
// window(contiguous subarray) of size K.


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> result;
    queue<int> neg;
    int j=0;
    for(int i=0; i<N; i++){
        if(A[i]<0){
            neg.push(A[i]);
        }
        
        if(i<K-1){
            continue;
        }
        if(i>K-1){
            if(A[j]<0){neg.pop();}
            j++;
        }
        if(!neg.empty()){result.push_back(neg.front());}
        else{result.push_back(0);}
    }
    return result;
}