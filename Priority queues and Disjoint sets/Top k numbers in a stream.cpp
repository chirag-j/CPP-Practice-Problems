#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return 2*i +1;
}
int right(int i){
    return 2*i +2;
}

void display(vector<int> v){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void display(vector<vector<int>> v){
    for(int i = 0; i<v.size(); i++){
        display(v[i]);
    }
    cout<<endl;
}

void siftUp(int x, vector<vector<int>> &pq){
    if(x>0 && pq[parent(x)][1] < pq[x][1]){
        swap(pq[parent(x)], pq[x]);
        siftUp(parent(x), pq);
    }
    else if(x>0 && pq[parent(x)][1] == pq[x][1]){
        if(pq[parent(x)][0] > pq[x][0]){
            swap(pq[parent(x)], pq[x]);
            siftUp(parent(x), pq);
        }
    }
}

void siftDown(int x, vector<vector<int>> &pq){
    int maxInd = x, size = pq.size();
    if(left(x)<size && pq[left(x)][1] > pq[x][1]){
        maxInd = left(x);
    }
    if(right(x)<size && pq[right(x)][1] > pq[x][1]){
        if(pq[left(x)][1] == pq[right(x)][1]){
            if(pq[left(x)][0]<pq[right(x)][0]){
                maxInd = left(x);
            }
            else{
                maxInd = right(x);
            }
        }
        else if(pq[right(x)][1] > pq[maxInd][1]) {
            maxInd = right(x);
        }
    }
    if(x!=maxInd){
        swap(pq[x], pq[maxInd]);
        siftDown(maxInd, pq);
    }
    else{
        if(left(x)<size && pq[left(x)][1] == pq[x][1]){
            if(pq[left(x)][0] < pq[x][0]){
                maxInd = left(x);
            }
        }
        if(right(x)<size && pq[right(x)][1] == pq[x][1]){
            if(pq[right(x)][0] < pq[maxInd][0]){
                maxInd = right(x);
            }
        }
        if(x!=maxInd){
            swap(pq[x], pq[maxInd]);
            siftDown(maxInd, pq);
        }
    }
}

int extractMax(vector<vector<int>> &pq){
    int x = pq[0][0];
    swap(pq[0], pq[pq.size()-1]);
    pq.erase(pq.end()-1);
    siftDown(0, pq);
    return x;
}

void insertPQ(int key, vector<vector<int>> &pq){
    int size = pq.size();
    for(int i=0; i<pq.size(); i++){
        if(pq[i][0] == key){
            pq[i][1]++;
            siftUp(i ,pq);
            return;
        }
    }
    pq.push_back({key,1});
    siftUp(size, pq);
}


vector<int> kTop(int a[], int n, int k) { 
    vector<vector<int>> pq;
    vector<int> ktp;
    for(int i=0; i<n; i++){
        insertPQ(a[i],pq);
        vector<vector<int>> temp(pq);
        int j=0;
        // cout<<a[i]<<"  ";
        while(temp.size()!=0 && j<k){
            // cout<<temp[0][0]<<"."<<temp[0][1]<<" ";
            ktp.push_back(extractMax(temp));
            j++;
        }
        // cout<<"  ";
        // for(int xy = 0; xy<pq.size(); xy++){
        //     cout<<pq[xy][0]<<" ";
        // }
        // cout<<endl;
    }
    return ktp;
}

int main(){
    int N=24, K=6, arr[] = {18, 11, 19, 14, 17, 4 ,4 ,5 ,12 ,13, 7, 7 ,11 ,19 ,16, 3 ,17, 20 ,11 ,17 ,15, 6, 4, 9};
    // vector<vector<int>> pq;
    // for(int i=0; i<N; i++){
    //     insertPQ(arr[i], pq);
    //     display(pq);
    // }
    // vector<vector<int>> temp(pq);
    // while(temp.size()!=0){
    //     cout<<extractMax(temp)<<endl;
    //     display(temp);
    // }
    // display(pq);
    display(kTop(arr, N, K));
    return 0;
}


// Its Correct output is:
// 18
// 11 18 
// 11 18 19 
// 11 14 18 19 
// 11 14 17 18 19 
// 4 11 14 17 18 19 
// 4 11 14 17 18 19 
// 4 5 11 14 17 18 
// 4 5 11 12 14 17 
// 4 5 11 12 13 14 
// 4 5 7 11 12 13 
// 4 7 5 11 12 13 
// 4 7 11 5 12 13 
// 4 7 11 19 5 12 4 7 11 19 5 12 4 7 11 19 3 5 4 7 11 17 19 3 4 7 11 17 19 3 11 4 7 17 19 3 11 17 4 7 19 3 11 17 4 7 19 3 11 17 4 7 19 3 4 11 17 7 19 3 4 11 17 7 19 3

// And Your Code's output is:
// 18 11 18 11 18 19 11 14 18 19 11 14 17 18 19 4 11 14 17 18 19 4 11 14 17 18 19 4 5 11 14 17 18 4 5 11 12 14 17 4 5 11 12 13 14 4 5 7 11 12 13 4 7 5 11 12 13 4 11 7 5 12 13 4 11 19 7 5 12 4 11 19 7 5 12 4 11 19 7 3 5 4 11 19 7 17 3 4 11 19 7 17 3 11 4 19 7 17 3 11 4 19 17 7 3 11 4 19 17 7 3 11 4 19 17 7 3 4 11 19 17 7 3 4 11 19 17 7 3
// 18 11 18 11 18 19 11 14 18 19 11 14 17 18 19 4 11 14 17 18 19 4 11 14 17 18 19 4 5 11 14 17 18 4 5 11 12 14 17 4 5 11 12 13 14 4 5 7 11 12 13 4 7 5 11 12 13 4 7 11 5 12 13 4 7 11 19 5 12 4 7 11 19 5 12 4 7 11 19 3 5 4 7 17 11 19 3 4 7 17 11 19 3 11 7 17 4 19 3 11 17 7 4 19 3 11 17 7 4 19 3 11 17 7 4 19 3 4 17 11 7 19 3 4 17 11 7 19 3

// Its Correct output is:
// 18 11 18 11 18 19 11 14 18 19 11 14 17 18 19 4 11 14 17 18 19 4 11 14 17 18 19 4 5 11 14 17 18 4 5 11 12 14 17 4 5 11 12 13 14 4 5 7 11 12 13 4 7 5 11 12 13 4 7 11 5 12 13 4 7 11 19 5 12 4 7 11 19 5 12 4 7 11 19 3 5 4 7 11 17 19 3 4 7 11 17 19 3 11 4 7 17 19 3 11 17 4 7 19 3 11 17 4 7 19 3 11 17 4 7 19 3 4 11 17 7 19 3 4 11 17 7 19 3

// And Your Code's output is:
// 18 11 18 11 18 19 11 14 18 19 11 14 17 18 19 4 11 14 17 18 19 4 11 14 17 18 19 4 5 11 14 17 18 4 5 11 12 14 17 4 5 11 12 13 14 4 5 7 11 12 13 4 7 5 11 12 13 4 7 11 5 12 13 4 7 11 19 5 12 4 7 11 19 5 12 4 7 11 19 3 5 4 7 17 11 19 3 4 7 17 11 19 3 11 7 17 4 19 3 11 17 7 4 19 3 11 17 7 4 19 3 11 17 7 4 19 3 4 17 11 7 19 3 4 17 11 7 19 3

// 18 11 18 11 18 19 11 14 18 19 11 14 17 18 19 4 11 14 17 18 19 4 11 14 17 18 19 4 5 11 14 17 18 4 5 11 12 14 17 4 5 11 12 13 14 4 5 7 11 12 13 4 7 5 11 12 13 4 7 11 5 12 13 4 7 11 19 5 12 4 7 11 19 5 12 4 7 11 19 3 5 4 7 11 17 19 3 4 7 11 17 19 3 11 4 7 17 19 3 11 17 4 7 19 3 11 17 4 7 19 3 11 17 4 7 19 3 4 11 17 7 19 3 4 11 17 7 19 3 