#include<iostream>
#include<vector>
using namespace std;

void printSeq(vector<int> memdp){

}

int recurSol(int n){
    // cout<<n<<endl;
    if(n==1){
        return 0;
    }
    int A = 1e6;
    if(n%3 == 0){
        A = 1 + recurSol(n/3);
    }
    if(n%2 == 0){
        A = min(A, 1 + recurSol(n/2));
    }
    return min(A, 1 + recurSol(n-1));
}
vector<int> mem;
int recurSolMemo(int n){
    // cout<<n<<endl;
    if(n==1){
        mem[n] = n;
        return 0;
    }
    if(mem[n]!=-1){
        return mem[n];
    }

    int A = 1e6;
    if(n%3 == 0){
        if(mem[n/3]!=-1){
            A = 1 + mem[n/3];
        }
        else{
            A = 1 + recurSolMemo(n/3);
        }
        
    }
    if(n%2 == 0){
        if(mem[n/2]!=-1){
            A = min(A, 1 + mem[n/2]);
        }
        else{
            A = min(A, 1 + recurSolMemo(n/2));
        }
    }
    if(mem[n-1]!=-1){
        A = min(A, mem[n-1]);
    }
    else{
        A = min(A, 1+recurSolMemo(n-1));
    }
    mem[n] = A;
    return mem[n];
}

int dynamicSol(int n){
    
}

int main(){
    int x = 10;
    // cout<<recurSol(x)<<endl;
    mem.clear();
    mem.assign(x+1, -1);
    cout<<recurSolMemo(x);
    
    return 0;
}