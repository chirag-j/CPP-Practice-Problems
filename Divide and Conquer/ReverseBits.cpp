#include<iostream>
#include<vector>
using namespace std;
// example
//Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
int main(){
    uint32_t n = 43261596, m = 0;
    for(int i=31; i>=0; i--){
        if(n & 1<<i){   //if 1
            m=m | (1<<(31-i));
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    cout<<endl<<m<<" "<<n;
    
    return 0;
}