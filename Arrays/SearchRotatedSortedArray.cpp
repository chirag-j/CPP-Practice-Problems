int search(int A[], int l, int h, int key){
    static const int n = h;

    if(l>h){return -1;}
    int mid = l + (h-l)/2;
    // cout<<l<<" "<<h<<" "<<mid<<endl;
    if(A[mid] == key){return mid;}
    if(A[l] <= A[mid]){
        if(key>=A[l] && key<=A[mid]){
            return search(A,l,mid-1,key);
        }
        else{
            return search(A,mid+1,h,key);
        }
        
    }
    else{
        if(key<=A[h] && key>=A[mid]){
            return search(A,mid+1,h,key);
        }
        else{
            return search(A,l,mid-1,key);
        }
    }
//complete the function here
}