// eg: 125 has 3 x 5's, each one of them is accounted, 1 by n/5, 1 by n/25, and last 1 by 1/125

int trailingZeroes(int n) {
    int count = 0, x = 5;
    while(n/x != 0){
        count+=(n/x);
        x*=5;
    }
    return count;
}