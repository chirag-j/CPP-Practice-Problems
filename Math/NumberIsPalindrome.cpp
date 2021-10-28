// eg : 39521
// 0 + 1 = 1
// 1*10 + 2 = 12
// 21*10 + 5 = 125
// 125*10 + 9 = 1259
// 1259*10 + 3 = 12593

bool isPalindrome(int x) {
    if(x<0){return false;}
    long long n = x, rev = 0;
    while(x != 0){
        rev = rev*10 + x%10;
        x = x/10;
    }
    cout<<rev;
    return n == rev;
}