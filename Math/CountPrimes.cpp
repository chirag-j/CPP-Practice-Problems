// Sieve of erastothenes
// for i from 2 to sqrt(n), mark all i's as non-prime
// Works because all numbers till 'n'(not including) who are non-prime,
// will have at least one prime factor except 1

int countPrimes(int n) {
    if(n<=2){return 0;}
    if(n==3){return 1;}
    if(n<=5){return 2;}
    vector<bool> prime(n+1,1);
    prime[1] = 0;
    int temp = 0, count=n-2;
    for(int i=2; i<sqrt(n); i++){
        int j=2;
        temp = i*(j++);
        if(prime[i]){
            while(temp<n){
                if(prime[temp]){
                    prime[temp] = 0;
                    count--;
                }
                temp = i*(j++);
            }
        }
    }
    return count;
}