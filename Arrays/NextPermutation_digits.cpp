// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. 
// If no such positive integer exists, return -1.

// Note that the returned integer should fit in 32-bit integer, 
// if there is a valid answer but it does not fit in 32-bit integer, return -1.

int nextGreaterElement(int n) {
    vector<int> digits;
    int x = n;
    while(x!=0){
        digits.push_back(x%10);
        x/=10;
    }
    if(digits.size()>10){return -1;}
    int k=-1, l=0;
    for(int i=1; i<digits.size(); i++){
        if(digits[i]<digits[i-1]){
            k=i;
            break;
        }
    }
    if(k==-1){
        return -1;
    }
    for(int i=0;i<digits.size();i++){
        if(digits[i]>digits[k]){
            swap(digits[i],digits[k]);
            break;
        }
    }
    reverse(digits.begin(), digits.begin()+k);
    x=0;
    long long res = 0;
    for(int i=0; i<digits.size();i++){
        res+=(digits[i]*pow(10,x));
        x++;
    }
    if(res>INT_MAX){return -1;}
    return res;
}