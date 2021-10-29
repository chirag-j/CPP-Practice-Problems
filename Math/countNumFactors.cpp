// formula to count number of factors
// if a1, a2, a3 is the number of occurence of each prime factor, then
// total number of factors = (a1+1)*(a2+1)*(a3+1)*...

int countFactors(int N){
    int c = 1, n=N, q = 0;
    if(n%2==0){
        while(n%2==0){
            q++;
            n/=2;
        }
    }
    c*=(q+1);
    for(int i=3; i<=sqrt(N); i++){
        if(i>sqrt(n)){break;}
        if(n%i==0){
            q = 0;
            while(n%i==0){
                q++;
                n/=i;
            }
            c*=(q+1);
        }
    }
    if(n>2){
        c*=2;
    }
    return c;
    //code here
}