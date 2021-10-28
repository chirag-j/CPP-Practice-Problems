int gcd(int A, int B) 
{
    if(B==0){
        return A;
    }
    return gcd(B, A%B);
    // code here
} 
int LCM(int A, int B){
    return (A*B)/gcd(A,B);
}