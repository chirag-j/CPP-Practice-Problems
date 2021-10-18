// Why Fenwick tree
// -> Store Prefix sum or cumulative sum
// Traditional method of making a cumulative sum array wont work because,
// for every update in the main array, it needs O(n) time to make changes in the cum_sum array

// Fenwick Tree
// O(nlogn) to create for 1st time
// O(logn) to update
// O(logn) for a query
// O(n) storage space


#include<iostream>
#include<vector>
using namespace std;

template<class T>
void display(vector<T> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int TwosCompliment(int x){
    // Find the leftmost set bit, keep inverting all the bits starting from there
    uint8_t temp = x;
    bool found_lsb = false;
    for(int i = 7; i>=0; i--){
        if(temp & (1<<i)){
            found_lsb = true;
        }
        if(found_lsb){
            if(temp & (1<<i)){
                temp = temp & (~(1<<i));
            }
            else{
                temp = temp | (1<<i);
            }
        }
    }
    return temp +1;
}

int getNext(int i){
    int temp = TwosCompliment(i);
    temp = temp & i;
    return temp + i;
}

int parent(int i){
    int temp = TwosCompliment(i);
    temp = temp & i;
    return i-temp;
}
class FenwickTree{
    public:
    int size;
    vector<int> tree;
    FenwickTree(int n){
        size = n+1;
        tree.resize(size);
    }
    FenwickTree(vector<int> &arr){
        createTree(arr);
    }
    void createTree(vector<int> &arr){
        size = arr.size()+1;
        tree.resize(size);
        tree[0] = 0;

        for(int i=0; i<size-1; i++){
            int x = i+1;
            tree[x] += arr[i];
            x = getNext(x);
            while(x < size){
                tree[x]+=arr[i];
                x = getNext(x);
            }
        }
    }
    void update(int i, int diff){
        int x = i+1;
        tree[x] += diff;
        x = getNext(x);
        while(x < size){
            tree[x] += diff;
            x = getNext(x);
        }
    }

    int get_range(int j){
        int sum = 0, x = j+1;
        if(x>=size){return -1;}
        while(x > 0){
            sum+=tree[x];
            x = parent(x);
        }
        return sum;
    }
    
};

int main(){
    vector<int> arr = {3,2,-1,6,5,4,-3,3,7,2,3};
    FenwickTree eg(arr);
    display(eg.tree);
    for(int i=0; i<arr.size(); i++){
        cout<<eg.get_range(i)<<endl;
    }
    // cout<<parent(3)<<endl;
    return 0;
}